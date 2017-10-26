#include <linux/module.h>   /* Buh moduld heregtei  */
#include <linux/kernel.h>   /*  KERN_INFO   */
#include <linux/init.h>     /* macro  */
#include <linux/list.h>     /* linked list */
#include <linux/types.h>    /* list macro */
#include <linux/slab.h>     /* Kernel */

#define NUM_OF_BIRTHDAYS    6

/* Birthday struct  */
typedef struct _birthday
{

    int day;
    int month;
    int year;
    struct list_head list;

} birthday;

/* Linked list tolgoi zarlaj init hiine */
LIST_HEAD(birthday_list);

/*
   Modul achaalah ued funkts duudagdana
   STRUCT utguud, sanah oid zai avj ehluulne(6)
   daraa n buh tursun udriig kernel log-d hevlene
*/
int birthdayList_init(void)
{

    printk(KERN_INFO "Loading Module\n");

    /* 5-iig huvaarlina */
    birthday *person;
    int i = 0;
    for(i = 0; i < NUM_OF_BIRTHDAYS; i++)
    {
        /* malloc ---> kernel. */
        person = kmalloc(sizeof(*person), GFP_KERNEL);
        /* utga onooh */
        person->day = 2 + i;
        person->month = 7 + i;
        person->year = 1995 + i;
        /* init  */
        INIT_LIST_HEAD(&person->list);
        /* list tugsguld tail bolno */
        list_add_tail(&person->list, &birthday_list);

    }

    /* hevleh. */
    birthday *ptr;
    list_for_each_entry(ptr, &birthday_list, list)
    {

        printk(KERN_INFO "Birthday: Month %d Day %d Year %d\n",
               ptr->month,
               ptr->day,
               ptr->year);
    }

    return 0;
}

/*
   modul avgdahad duudagdah funkts
   ustgagdah t.u hevlene, listiig kernel sanah oigoos   ustgana
*/
void birthdayList_exit(void)
{

    printk(KERN_INFO "Removing Module\n");

    /* sanah oi cholooloh */
    birthday *ptr, *next;
    list_for_each_entry_safe(ptr, next, &birthday_list, list)
    {

        printk(KERN_INFO "Removing Birthday: Month %d Day %d Year %d\n",
               ptr->month,
               ptr->day,
               ptr->year);
        /*list ustgah*/
        list_del(&ptr->list);
        /*list sanah oi chuluul*/
        kfree(ptr);

    }

    printk(KERN_INFO "Memory free done\n");

}

/* modul oroh garah burtgegdeg macro */
module_init(birthdayList_init);
module_exit(birthdayList_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("LAB02");
MODULE_AUTHOR("GTS");
