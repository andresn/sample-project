
    const struct cred *cred = current_cred();

    int retval = 1;



    if (grp != cred->fsgid)

        retval = groups_search(cred->group_info, grp);

    return retval;
