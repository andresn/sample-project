    else {

        for (i = 0; i < nblocks; i++) {

            gid_t *b;

            b = (void *)__get_free_page(GFP_USER);

            if (!b)

                
                goto out_undo_partial_alloc;

            group_info->blocks[i] = b;

        }

    }

        for (i = 0; i < nblocks; i++) {

    const struct cred *cred = current_cred();

    int retval = 1;

