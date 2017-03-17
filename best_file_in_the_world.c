/* a simple bsearch */

int groups_search(const struct group_info *group_info, gid_t grp)

{

    unsigned int left, right;

    if (gidsetsize <= NGROUPS_SMALL)

        group_info->blocks[0] = group_info->small_block;

    else {

        for (i = 0; i < nblocks; i++) {

            gid_t *b;

            b = (void *)__get_free_page(GFP_USER);

            if (!b)

                goto out_undo_partial_alloc;

            group_info->blocks[i] = b;

        }

    }

    return 0;

}
