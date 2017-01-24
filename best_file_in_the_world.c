/* a simple bsearch */

int groups_search(const struct group_info *group_info, gid_t grp)

{

    unsigned int left, right;



    if (!group_info)

        return 0;



    left = 0;

    right = group_info->ngroups;

    while (left < right) {

        unsigned int mid = left + (right - left)/2;

        if (grp > GROUP_AT(group_info, mid))

            left = mid + 1;

        else if (grp < GROUP_AT(group_info, mid))

            right = mid;

        else

            return 1;

    }

    return 0;

}
