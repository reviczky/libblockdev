static const gchar const * const mpath_functions[] = {
    "bd_mpath_flush_mpaths",
    "bd_mpath_is_mpath_member",
    "bd_mpath_set_friendly_names",
    NULL};

gchar const * const * get_mpath_functions (void) {
    return mpath_functions;
}

static const guint8 mpath_num_functions = 3;

guint8 get_mpath_num_functions (void) {
    return mpath_num_functions;
}

gboolean  bd_mpath_flush_mpaths_stub (GError **error) {
    g_critical ("The function 'bd_mpath_flush_mpaths' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_mpath_flush_mpaths' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_mpath_flush_mpaths) (GError **error) = bd_mpath_flush_mpaths_stub;

/**
 * bd_mpath_flush_mpaths:
 * @error: (out): place to store error (if any)
 *
 * Returns: whether multipath device maps were successfully flushed or not
 *
 * Flushes all unused multipath device maps.
 */
gboolean  bd_mpath_flush_mpaths (GError **error) {
    return _bd_mpath_flush_mpaths (error);
}


gboolean  bd_mpath_is_mpath_member_stub (gchar *device, GError **error) {
    g_critical ("The function 'bd_mpath_is_mpath_member' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_mpath_is_mpath_member' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_mpath_is_mpath_member) (gchar *device, GError **error) = bd_mpath_is_mpath_member_stub;

/**
 * bd_mpath_is_mpath_member:
 * @device: device to test
 * @error: (out): place to store error (if any)
 *
 * Returns: %TRUE if the device is a multipath member, %FALSE if not or an error
 * appeared when queried (@error is set in those cases)
 */
gboolean  bd_mpath_is_mpath_member (gchar *device, GError **error) {
    return _bd_mpath_is_mpath_member (device, error);
}


gboolean  bd_mpath_set_friendly_names_stub (gboolean enabled, GError **error) {
    g_critical ("The function 'bd_mpath_set_friendly_names' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_mpath_set_friendly_names' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_mpath_set_friendly_names) (gboolean enabled, GError **error) = bd_mpath_set_friendly_names_stub;

/**
 * bd_mpath_set_friendly_names:
 * @enabled: whether friendly names should be enabled or not
 * @error: (out): place to store error (if any)
 *
 * Returns: if successfully set or not
 */
gboolean  bd_mpath_set_friendly_names (gboolean enabled, GError **error) {
    return _bd_mpath_set_friendly_names (enabled, error);
}


gpointer load_mpath_from_plugin(gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module mpath: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "check");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for mpath: %s", error);
    if (check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for mpath: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_mpath_flush_mpaths) = dlsym(handle, "bd_mpath_flush_mpaths");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_mpath_flush_mpaths: %s", error);

    dlerror();
    * (void**) (&_bd_mpath_is_mpath_member) = dlsym(handle, "bd_mpath_is_mpath_member");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_mpath_is_mpath_member: %s", error);

    dlerror();
    * (void**) (&_bd_mpath_set_friendly_names) = dlsym(handle, "bd_mpath_set_friendly_names");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_mpath_set_friendly_names: %s", error);

    return handle;
}

gboolean unload_mpath (gpointer handle) {
    _bd_mpath_flush_mpaths = bd_mpath_flush_mpaths_stub;
    _bd_mpath_is_mpath_member = bd_mpath_is_mpath_member_stub;
    _bd_mpath_set_friendly_names = bd_mpath_set_friendly_names_stub;

    return dlclose(handle) == 0;
}

