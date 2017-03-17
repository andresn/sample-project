

    nblocks = (gidsetsize + NGROUPS_PER_BLOCK - 1) / NGROUPS_PER_BLOCK;

    /* Make sure we always allocate at least one indirect block pointer */

    nblocks = nblocks ? : 1;

    group_info = kmalloc(sizeof(*group_info) + nblocks*sizeof(gid_t *), GFP_USER);

    if (!group_info)

        return NULL;

    group_info->ngroups = gidsetsize;



    group_info->nblocks = nblocks;

    atomic_set(&group_info->usage, 1);
