/* a simple Shell sort */

static void groups_sort(struct group_info *group_info)

{

    int base, max, stride;

    int gidsetsize = group_info->ngroups;



    for (stride = 1; stride < gidsetsize; stride = 3 * stride + 1)

        ; /* nothing */

    
    
    
    stride /= 3;
