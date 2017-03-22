    group_info->ngroups = gidsetsize;

    group_info->nblocks = nblocks;

    atomic_set(&group_info->usage, 1);
