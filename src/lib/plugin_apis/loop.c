static const gchar const * const loop_functions[] = {
    "bd_loop_get_backing_file",
    "bd_loop_get_loop_name",
    "bd_loop_setup",
    "bd_loop_teardown",
    NULL};

gchar const * const * get_loop_functions (void) {
    return loop_functions;
}

static const guint8 loop_num_functions = 4;

guint8 get_loop_num_functions (void) {
    return loop_num_functions;
}

gchar* bd_loop_get_backing_file_stub (gchar *dev_name, GError **error) {
    g_critical ("The function 'bd_loop_get_backing_file' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_get_backing_file' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_loop_get_backing_file) (gchar *dev_name, GError **error) = bd_loop_get_backing_file_stub;

/**
 * bd_loop_get_backing_file:
 * @dev_name: name of the loop device to get backing file for (e.g. "loop0")
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): path of the device's backing file or %NULL if none
 *                           is found
 */
gchar* bd_loop_get_backing_file (gchar *dev_name, GError **error) {
    return _bd_loop_get_backing_file (dev_name, error);
}


gchar* bd_loop_get_loop_name_stub (gchar *file, GError **error) {
    g_critical ("The function 'bd_loop_get_loop_name' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_get_loop_name' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_loop_get_loop_name) (gchar *file, GError **error) = bd_loop_get_loop_name_stub;

/**
 * bd_loop_get_loop_name:
 * @file: path of the backing file to get loop name for
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): name of the loop device associated with the given @file
 */
gchar* bd_loop_get_loop_name (gchar *file, GError **error) {
    return _bd_loop_get_loop_name (file, error);
}


gboolean  bd_loop_setup_stub (gchar *file, gchar **loop_name, GError **error) {
    g_critical ("The function 'bd_loop_setup' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_setup' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_loop_setup) (gchar *file, gchar **loop_name, GError **error) = bd_loop_setup_stub;

/**
 * bd_loop_setup:
 * @file: file to setup as a loop device
 * @loop_name: (out): if not %NULL, it is used to store the name of the loop device
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @file was successfully setup as a loop device or not
 */
gboolean  bd_loop_setup (gchar *file, gchar **loop_name, GError **error) {
    return _bd_loop_setup (file, loop_name, error);
}


gboolean  bd_loop_teardown_stub (gchar *loop, GError **error) {
    g_critical ("The function 'bd_loop_teardown' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_loop_teardown' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_loop_teardown) (gchar *loop, GError **error) = bd_loop_teardown_stub;

/**
 * bd_loop_teardown:
 * @loop: path or name of the loop device to tear down
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @loop device was successfully torn down or not
 */
gboolean  bd_loop_teardown (gchar *loop, GError **error) {
    return _bd_loop_teardown (loop, error);
}


gpointer load_loop_from_plugin(gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module loop: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "check");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for loop: %s", error);
    if (check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for loop: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_loop_get_backing_file) = dlsym(handle, "bd_loop_get_backing_file");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_get_backing_file: %s", error);

    dlerror();
    * (void**) (&_bd_loop_get_loop_name) = dlsym(handle, "bd_loop_get_loop_name");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_get_loop_name: %s", error);

    dlerror();
    * (void**) (&_bd_loop_setup) = dlsym(handle, "bd_loop_setup");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_setup: %s", error);

    dlerror();
    * (void**) (&_bd_loop_teardown) = dlsym(handle, "bd_loop_teardown");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_loop_teardown: %s", error);

    return handle;
}

gboolean unload_loop (gpointer handle) {
    _bd_loop_get_backing_file = bd_loop_get_backing_file_stub;
    _bd_loop_get_loop_name = bd_loop_get_loop_name_stub;
    _bd_loop_setup = bd_loop_setup_stub;
    _bd_loop_teardown = bd_loop_teardown_stub;

    return dlclose(handle) == 0;
}

