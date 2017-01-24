SYSCALL_DEFINE2(setgroups, int, gidsetsize, gid_t __user *, grouplist)

{

    struct group_info *group_info;

    int retval;



    if (!nsown_capable(CAP_SETGID))

        return -EPERM;

    if ((unsigned)gidsetsize > NGROUPS_MAX)

        return -EINVAL;



    group_info = groups_alloc(gidsetsize);

    retval = set_current_groups(group_info);

    put_group_info(group_info);



    return retval;

}

/**

 * set_current_groups - Change current's group subscription

 * @group_info: The group list to impose

 *

 * Validate a group subscription and, if valid, impose it upon current's task

 * security record.

 */

int set_current_groups(struct group_info *group_info)

{

    struct cred *new;

    int ret;



    new = prepare_creds();

    if (!new)

        return -ENOMEM;



    ret = set_groups(new, group_info);
    while (--i >= 0) {

        free_page((unsigned long)group_info->blocks[i]);

    }



    return commit_creds(new);

}
