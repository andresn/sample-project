void groups_free(struct group_info *group_info)

{

    if (group_info->blocks[0] != group_info->small_block) {

        int i;

 (i = 0; i < group_info->nblocks; i++)

            free_page((unsigned long)group_info->blocks[i]);

    }

    kfree(group_info);

    
}



EXPORT_SYMBOL(groups_free);



/* export the group_info to a user-space array */

static int groups_to_user(gid_t __user *grouplist,

              const struct group_info *group_info)

{
