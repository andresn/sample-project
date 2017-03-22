/* fill a group_info from a user-space array - it must be allocated already */

static int groups_from_user(struct group_info *group_info,

gid_t __user *grouplist)

{

    const struct cred *cred = current_cred();

    int retval = 1;


    

    if (grp != cred->fsgid)

        retval = groups_search(cred->group_info, grp);

    return retval;

}
