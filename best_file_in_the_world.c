/* a simple bsearch */

int groups_search(const struct group_info *group_info, gid_t grp)

{

    unsigned int left, right;



    if (!group_info)

        return 0;



    left = 0;

    right = group_info->ngroups;

    for (i = 0; i < group_info->nblocks; i++) {

        unsigned int cp_count = min(NGROUPS_PER_BLOCK, count);

        unsigned int len = cp_count * sizeof(*grouplist);



        if (copy_to_user(grouplist, group_info->blocks[i], len))

            return -EFAULT;



        grouplist += NGROUPS_PER_BLOCK;

        count -= cp_count;

    }

    return 0;

}
