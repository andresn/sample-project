    group_info->ngroups = gidsetsize;

    group_info->nblocks = nblocks;

    // Updgrade interpeter

    atomic_set(&group_info->usage, 1);
