// Macros used to mark up functions e.g. __init __exit
#include <linux/init.h>

 // Core header for loading LKMs into the kernel
#include <linux/module.h> 

 // Header to support the kernel Driver Model
#include <linux/device.h> 

 // Contains types, macros, functions for the kernel
#include <linux/kernel.h>

 // Header for the Linux file system support
#include <linux/fs.h>

 // Required for the copy to user function
#include <asm/uaccess.h>

// The device will appear at /dev/char using this value
#define  DEVICE_NAME "Marvellous_Driver_1"

// The device class -- this is a character device driver
#define  CLASS_NAME  "Marvellous_Driver"        

// The license type -- this affects available functionality
MODULE_LICENSE("GPL");

// The author -- visible when you use modinfo
MODULE_AUTHOR("Piyush Khairnar");


MODULE_DESCRIPTION("Marvellous : Demo character driver");

// A version number to inform users
MODULE_VERSION("0.1");

// Stores the device number -- determined automatically
static int    majorNumber;

// Memory for the string that is passed from userspace
static char   message[256] = {0};       

// Used to remember the size of the string stored
static short  size_of_message;           

// Counts the number of times the device is opened
static int    numberOpens = 0;             

// The device-driver class struct pointer
static struct class*  charClass  = NULL;
 
static struct device* charDevice = NULL;  

// The prototype functions for the character driver -- must come before the struct definition
static int     dev_open(struct inode *, struct file *);

static int     dev_release(struct inode *, struct file *);

static ssize_t dev_read(struct file *, char *, size_t, loff_t *);

static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);
 
// Initialise file_operations structure
static struct file_operations fops =
{
   .open = dev_open,
   .read = dev_read,
   .write = dev_write,
   .release = dev_release,
};
 
//////////////////////////////////////////////////////////////////////////////////////////////////
// Driver initialisation function

static int __init char_init(void)
{
	printk(KERN_INFO "Marvellous : Driver loaded successfully\n");

	//Allocate a major number for the device
	majorNumber = register_chrdev(0, DEVICE_NAME, &fops);

	// If there is a problem in major number allocation   
	if (majorNumber<0)
	{
		printk(KERN_ALERT "Marvellous : failed to register a major number\n");

		return majorNumber;
	}

	printk(KERN_INFO "Marvellous : registered correctly with major number %d\n", majorNumber);

	// Register the device class
	charClass = class_create(THIS_MODULE, CLASS_NAME);

	if (IS_ERR(charClass))
	{
		unregister_chrdev(majorNumber, DEVICE_NAME);

		printk(KERN_ALERT "Failed to register device class\n");

		return PTR_ERR(charClass); 
	}

	printk(KERN_INFO "Marvellous : device class registered correctly\n");

	// Register the device driver
	charDevice = device_create(charClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);

	if (IS_ERR(charDevice))
	{               // Clean up if there is an error
		class_destroy(charClass); 

		unregister_chrdev(majorNumber, DEVICE_NAME);

		printk(KERN_ALERT "Failed to create the device\n");
		return PTR_ERR(charDevice);
	}

	printk(KERN_INFO "Marvellous : device class created correctly\n");

	return 0;
}
 //////////////////////////////////////////////////////////////////////////////////////////////////

// Driver cleanup function

static void __exit char_exit(void)
{
	// remove the device
	device_destroy(charClass, MKDEV(majorNumber, 0));

	// unregister the device class
	class_unregister(charClass);

	// remove the device class
	class_destroy(charClass); 

	// unregister the major number
	unregister_chrdev(majorNumber, DEVICE_NAME);
	printk(KERN_INFO "Marvellous : Goodbye from our driver!\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////// 

// Function which gets called when we open the device

static int dev_open(struct inode *inodep, struct file *filep)
{
	numberOpens++;

	printk(KERN_INFO "Marvellous :  Device has been opened %d time(s)\n", numberOpens);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
// Function is called whenever device is being read from user space i.e. data is

/*
filep :	A pointer to a file object (defined in linux/fs.h)
buffer:	The pointer to the buffer to which this function writes the data
len :	The length of the b
offset:	The offset if required
*/

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset)
{
	int error_count = 0;
	// copy_to_user has the format ( * to, *from, size) and returns 0 on success
	error_count = raw_copy_to_user(buffer, message, size_of_message);

	if (error_count==0)
	{            // if true then have success
		printk(KERN_INFO "Marvellous :  Sent %d characters to the user\n", size_of_message);
		
		return (size_of_message=0);  // clear the position to the start and return 0
	}
	else 
	{
		printk(KERN_INFO "Marvellous :  Failed to send %d characters to the user\n", error_count);

		return -EFAULT;              // Failed -- return a bad address message (i.e. -14)
	}
}
 //////////////////////////////////////////////////////////////////////////////////////////////////

//This function is called whenever the device is being written to from user space i.e.
// data is sent to the device from the user. The data is copied to the message[] array in this
/*
filep:	 A pointer to a file object
buffer:	 The buffer to that contains the string to write to the device
len:	 	The length of the array of data that is being passed in the const char buffer
offset:	 The offset if required
*/

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
	sprintf(message, "%s(%ld letters)", buffer, len);   // appending received string with its length

	size_of_message = strlen(message);                 // store the length of the stored message

	printk(KERN_INFO "Marvellous :  Received %ld characters from the user\n", len);

	return len;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
// The device release function that is called whenever the device is closed/released by the userspace program
/*
inodep:	 A pointer to an inode object (defined in linux/fs.h)
filep:	 A pointer to a file object (defined in linux/fs.h)
*/

static int dev_release(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Marvellous :  Device successfully closed\n");

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 

module_init(char_init);
module_exit(char_exit);
