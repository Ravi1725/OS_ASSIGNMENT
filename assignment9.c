#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

//MODULE_LICENSE("GPL");
//MODULE_AUTHOR("Rj");
static int myint = 420;
//module param takes 3 arguments: name, type and permission

//Lastly, there's a macro function, MODULE_PARM_DESC(), that is used to
//document arguments that the
//module can take. It takes two parameters: a variable name and a free f
//orm string describing that variable.
//S_IRUSR----- STAT INODE READ USER, GROUP, OTHERS
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
//Printk------ It happens to be a logging mechanism for the kernel,
//and is used to log information or give warnings.
/*
If the priority is less than int console_loglevel, the message is printe
d on your current terminal. If
both syslogd and klogd are running, then the message will also get appen
ded to /var/log/messages,
whether it got printed to the console or not. We use a high priority, li
ke KERN_ALERT, to make sure the
printk() messages get printed to your console rather than just logged to
 your logfile.


*/
static int __init hello_5_init(void)
{
        int i;
        printk(KERN_INFO "myint is an integer: %d\n", myint);
        return 0;
}

static void __exit hello_5_exit(void)
{
        printk(KERN_INFO "world is the best 5\n");
}

module_init(hello_5_init);//marking function to be used as entry point
module_exit(hello_5_exit);//marking function to be used as exit function

