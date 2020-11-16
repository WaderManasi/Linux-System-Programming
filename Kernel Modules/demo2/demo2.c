
// This header file is required by all kernel modules
#include <linux/module.h>
// This header file is required for KERN_INFO
#include <linux/kernel.h>
#include <linux/stat.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

#define AUTHOR "Manasi Wader"
#define DESC "Demo kernel module "
//good practice to write this

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);

// This function gets called automattically when module gets loaded by insmod
int no=11;

module_param(no //variable name
                                ,int, //data type
                                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); //permission 
                                        //macro

//command line input

MODULE_PARAM_DESC(no,"Integer Variable");

int start(void)
{
	printk(KERN_INFO "MModule DEMO : Module loaded %d \n",no);
	return 0;
}

// This function gets called automatically when module gets removed from memory by rmmod
void end(void)
{
	printk(KERN_INFO "MModule DEMO : Module removed\n");
}

//register the names of callback functions
module_init(start);
module_exit(end);
// All the information which is printed by printk function is available in /var/log/syslog file.
