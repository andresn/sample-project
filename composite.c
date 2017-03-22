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



    nblocks = (gidsetsize + NGROUPS_PER_BLOCK - 1) / NGROUPS_PER_BLOCK;

    /* Make sure we always allocate at least one indirect block pointer */

    nblocks = nblocks ? : 1;

    group_info = kmalloc(sizeof(*group_info) + nblocks*sizeof(gid_t *), GFP_USER);

    if (!group_info)

        return NULL;

    group_info->ngroups = gidsetsize;

    group_info->nblocks = nblocks;

    atomic_set(&group_info->usage, 1);
