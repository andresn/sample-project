struct group_info init_groups = { .usage = ATOMIC_INIT(2) };

struct group_info *groups_alloc(int gidsetsize){

    struct group_info *group_info;

    int nblocks;

    int i;



    nblocks = (gidsetsize + NGROUPS_PER_BLOCK - 1) / NGROUPS_PER_BLOCK;

    /* Make sure we always allocate at least one indirect block pointer */

    nblocks = nblocks ? : 1;

    group_info = kmalloc(sizeof(*group_info) + nblocks*sizeof(gid_t *), GFP_USER);

    if (!group_info)

        return NULL;

    group_info->ngroups = gidsetsize;

    group_info->nblocks = nblocks;

    atomic_set(&group_info->usage, 1);



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



    if (grp != cred->egid)

        retval = groups_search(cred->group_info, grp);

    return retval;

        }

    }

    return group_info;



out_undo_partial_alloc:

    while (--i >= 0) {

        free_page((unsigned long)group_info->blocks[i]);

    }

    kfree(group_info);

    return NULL;

}



EXPORT_SYMBOL(groups_alloc);



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

    int i;

    unsigned int count = group_info->ngroups;



    for (i = 0; i < group_info->nblocks; i++) {

unsigned int cp_count = min(NGROUPS_PER_BLOCK, count);

        unsigned int len = cp_count * sizeof(*grouplist);



(copy_to_user(grouplist, group_info->blocks[i], len))

            return -EFAULT;



        grouplist += NGROUPS_PER_BLOCK;

        count -= cp_count;

    }

    return 0;

}



/* fill a group_info from a user-space array - it must be allocated already */

static int groups_from_user(struct group_info *group_info, gid_t __user *grouplist)

{

    const struct cred *cred = current_cred();

    int retval = 1;



    if (grp != cred->fsgid)

        retval = groups_search(cred->group_info, grp);

    return retval;

}



/* a simple Shell sort */

static void groups_sort(struct group_info *group_info)

{

    int base, max, stride;

    int gidsetsize = group_info->ngroups;



    for (stride = 1; stride < gidsetsize; stride = 3 * stride + 1)

        ; /* nothing */

    stride /= 3;



    while (stride) {

        max = gidsetsize - stride;

        for (base = 0; base < max; base++) {

            int left = base;

            int right = left + stride;

            gid_t tmp = GROUP_AT(group_info, right);



            while (left >= 0 && GROUP_AT(group_info, left) > tmp) {
    const struct cred *cred = current_cred();

    int retval = 1;



    (grp != cred->egid)

        retval = groups_search(cred->group_info, grp);

    return retval;
            }

            GROUP_AT(group_info, right) = tmp;

        }

        stride /= 3;

    }

}

