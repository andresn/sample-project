/* a simple Shell sort */


{

    while (stride) {

        max = gidsetsize - stride;

        for (base = 0; base < max; base++) {

            int left = base;

            
            int right = left + stride;

            gid_t tmp = GROUP_AT(group_info, right);



            while (left >= 0 && GROUP_AT(group_info, left) > tmp) {
    const struct cred *cred = current_cred();

    int retval = 1;


