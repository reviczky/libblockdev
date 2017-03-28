static const gchar const * const s390_functions[] = {
    "bd_s390_dasd_format",
    "bd_s390_dasd_needs_format",
    "bd_s390_dasd_online",
    "bd_s390_dasd_is_ldl",
    "bd_s390_sanitize_dev_input",
    "bd_s390_zfcp_sanitize_wwpn_input",
    "bd_s390_zfcp_sanitize_lun_input",
    NULL};

gchar const * const * get_s390_functions (void) {
    return s390_functions;
}

static const guint8 s390_num_functions = 7;

guint8 get_s390_num_functions (void) {
    return s390_num_functions;
}

gboolean  bd_s390_dasd_format_stub (const gchar *dasd, GError **error) {
    g_critical ("The function 'bd_s390_dasd_format' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_dasd_format' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_dasd_format) (const gchar *dasd, GError **error) = bd_s390_dasd_format_stub;

/**
 * bd_s390_dasd_format:
 * @dasd: dasd to format
 * @error: (out): place to store error (if any)
 *
 * Returns: whether dasdfmt was successful or not
 */
gboolean  bd_s390_dasd_format (const gchar *dasd, GError **error) {
    return _bd_s390_dasd_format (dasd, error);
}


gboolean  bd_s390_dasd_needs_format_stub (const gchar *dasd, GError **error) {
    g_critical ("The function 'bd_s390_dasd_needs_format' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_dasd_needs_format' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_dasd_needs_format) (const gchar *dasd, GError **error) = bd_s390_dasd_needs_format_stub;

/**
 * bd_s390_dasd_needs_format:
 * @dasd: dasd to check, whether it needs dasdfmt run on it
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a dasd needs dasdfmt run against it
 */
gboolean  bd_s390_dasd_needs_format (const gchar *dasd, GError **error) {
    return _bd_s390_dasd_needs_format (dasd, error);
}


gboolean  bd_s390_dasd_online_stub (gchar *dasd, GError **error) {
    g_critical ("The function 'bd_s390_dasd_online' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_dasd_online' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_dasd_online) (gchar *dasd, GError **error) = bd_s390_dasd_online_stub;

/**
 * bd_s390_dasd_online:
 * @dasd: dasd to switch online
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a dasd was successfully switched online
 */
gboolean  bd_s390_dasd_online (gchar *dasd, GError **error) {
    return _bd_s390_dasd_online (dasd, error);
}


gboolean  bd_s390_dasd_is_ldl_stub (const gchar *dasd, GError **error) {
    g_critical ("The function 'bd_s390_dasd_is_ldl' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_dasd_is_ldl' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_s390_dasd_is_ldl) (const gchar *dasd, GError **error) = bd_s390_dasd_is_ldl_stub;

/**
 * bd_s390_dasd_is_Ldl:
 * @dasd: dasd to check, whether it is LDL formatted
 * @error: (out): place to store error (if any)
 *
 * Returns: whether a dasd is LDL formatted
 */
gboolean  bd_s390_dasd_is_ldl (const gchar *dasd, GError **error) {
    return _bd_s390_dasd_is_ldl (dasd, error);
}


gchar* bd_s390_sanitize_dev_input_stub (const gchar *dev, GError **error) {
    g_critical ("The function 'bd_s390_sanitize_dev_input' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_sanitize_dev_input' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_s390_sanitize_dev_input) (const gchar *dev, GError **error) = bd_s390_sanitize_dev_input_stub;

/**
 * bd_s390_sanitize_dev_input:
 * @dev a DASD or zFCP device number
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): a synthesized dasd or zfcp device number
 */
gchar* bd_s390_sanitize_dev_input (const gchar *dev, GError **error) {
    return _bd_s390_sanitize_dev_input (dev, error);
}


gchar* bd_s390_zfcp_sanitize_wwpn_input_stub (const gchar *wwpn, GError **error) {
    g_critical ("The function 'bd_s390_zfcp_sanitize_wwpn_input' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_zfcp_sanitize_wwpn_input' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_s390_zfcp_sanitize_wwpn_input) (const gchar *wwpn, GError **error) = bd_s390_zfcp_sanitize_wwpn_input_stub;

/**
 * bd_s390_zfcp_sanitize_wwpn_input:
 * @wwpn a zFCP WWPN identifier
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): a synthesized zFCP WWPN
 */
gchar* bd_s390_zfcp_sanitize_wwpn_input (const gchar *wwpn, GError **error) {
    return _bd_s390_zfcp_sanitize_wwpn_input (wwpn, error);
}


gchar* bd_s390_zfcp_sanitize_lun_input_stub (const gchar *lun, GError **error) {
    g_critical ("The function 'bd_s390_zfcp_sanitize_lun_input' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_s390_zfcp_sanitize_lun_input' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_s390_zfcp_sanitize_lun_input) (const gchar *lun, GError **error) = bd_s390_zfcp_sanitize_lun_input_stub;

/**
 * bd_s390_zfcp_sanitize_lun_input:
 * @lun a zFCP LUN identifier
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): a synthesized zFCP LUN
 */
gchar* bd_s390_zfcp_sanitize_lun_input (const gchar *lun, GError **error) {
    return _bd_s390_zfcp_sanitize_lun_input (lun, error);
}


gpointer load_s390_from_plugin(gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module s390: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "check");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for s390: %s", error);
    if (check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for s390: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_s390_dasd_format) = dlsym(handle, "bd_s390_dasd_format");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_dasd_format: %s", error);

    dlerror();
    * (void**) (&_bd_s390_dasd_needs_format) = dlsym(handle, "bd_s390_dasd_needs_format");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_dasd_needs_format: %s", error);

    dlerror();
    * (void**) (&_bd_s390_dasd_online) = dlsym(handle, "bd_s390_dasd_online");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_dasd_online: %s", error);

    dlerror();
    * (void**) (&_bd_s390_dasd_is_ldl) = dlsym(handle, "bd_s390_dasd_is_ldl");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_dasd_is_ldl: %s", error);

    dlerror();
    * (void**) (&_bd_s390_sanitize_dev_input) = dlsym(handle, "bd_s390_sanitize_dev_input");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_sanitize_dev_input: %s", error);

    dlerror();
    * (void**) (&_bd_s390_zfcp_sanitize_wwpn_input) = dlsym(handle, "bd_s390_zfcp_sanitize_wwpn_input");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_zfcp_sanitize_wwpn_input: %s", error);

    dlerror();
    * (void**) (&_bd_s390_zfcp_sanitize_lun_input) = dlsym(handle, "bd_s390_zfcp_sanitize_lun_input");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_s390_zfcp_sanitize_lun_input: %s", error);

    return handle;
}

gboolean unload_s390 (gpointer handle) {
    _bd_s390_dasd_format = bd_s390_dasd_format_stub;
    _bd_s390_dasd_needs_format = bd_s390_dasd_needs_format_stub;
    _bd_s390_dasd_online = bd_s390_dasd_online_stub;
    _bd_s390_dasd_is_ldl = bd_s390_dasd_is_ldl_stub;
    _bd_s390_sanitize_dev_input = bd_s390_sanitize_dev_input_stub;
    _bd_s390_zfcp_sanitize_wwpn_input = bd_s390_zfcp_sanitize_wwpn_input_stub;
    _bd_s390_zfcp_sanitize_lun_input = bd_s390_zfcp_sanitize_lun_input_stub;

    return dlclose(handle) == 0;
}

