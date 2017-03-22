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



