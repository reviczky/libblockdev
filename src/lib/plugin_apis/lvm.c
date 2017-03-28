/**
 * bd_lvm_pvdata_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDLVMPVdata* bd_lvm_pvdata_copy (BDLVMPVdata *data) {
        BDLVMPVdata *new_data = g_new0 (BDLVMPVdata, 1);

    new_data->pv_name = g_strdup (data->pv_name);
    new_data->pv_uuid = g_strdup (data->pv_uuid);
    new_data->pv_free = data->pv_free;
    new_data->pv_size = data->pv_size;
    new_data->pe_start = data->pe_start;
    new_data->vg_name = g_strdup (data->vg_name);
    new_data->vg_size = data->vg_size;
    new_data->vg_free = data->vg_free;
    new_data->vg_extent_size = data->vg_extent_size;
    new_data->vg_extent_count = data->vg_extent_count;
    new_data->vg_free_count = data->vg_free_count;
    new_data->vg_pv_count = data->vg_pv_count;

    return new_data;
}

/**
 * bd_lvm_pvdata_free: (skip)
 *
 * Frees @data.
 */
void  bd_lvm_pvdata_free (BDLVMPVdata *data) {
        g_free (data->pv_name);
    g_free (data->pv_uuid);
    g_free (data->vg_name);
    g_free (data);
}

GType  bd_lvm_pvdata_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDLVMPVdata",
                                            (GBoxedCopyFunc) bd_lvm_pvdata_copy,
                                            (GBoxedFreeFunc) bd_lvm_pvdata_free);
    }

    return type;
}

/**
 * bd_lvm_vgdata_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDLVMVGdata* bd_lvm_vgdata_copy (BDLVMVGdata *data) {
        BDLVMVGdata *new_data = g_new0 (BDLVMVGdata, 1);

    new_data->name = g_strdup (data->name);
    new_data->uuid = g_strdup (data->uuid);
    new_data->size = data->size;
    new_data->free = data->free;
    new_data->extent_size = data->extent_size;
    new_data->extent_count = data->extent_count;
    new_data->free_count = data->free_count;
    new_data->pv_count = data->pv_count;

    return new_data;
}

/**
 * bd_lvm_vgdata_free: (skip)
 *
 * Frees @data.
 */
void  bd_lvm_vgdata_free (BDLVMVGdata *data) {
        g_free (data->name);
    g_free (data->uuid);
    g_free (data);
}

GType  bd_lvm_vgdata_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDLVMVGdata",
                                            (GBoxedCopyFunc) bd_lvm_vgdata_copy,
                                            (GBoxedFreeFunc) bd_lvm_vgdata_free);
    }

    return type;
}

/**
 * bd_lvm_lvdata_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDLVMLVdata* bd_lvm_lvdata_copy (BDLVMLVdata *data) {
        BDLVMLVdata *new_data = g_new0 (BDLVMLVdata, 1);

    new_data->lv_name = g_strdup (data->lv_name);
    new_data->vg_name = g_strdup (data->vg_name);
    new_data->uuid = g_strdup (data->uuid);
    new_data->size = data->size;
    new_data->attr = g_strdup (data->attr);
    new_data->segtype = g_strdup (data->segtype);
    return new_data;
}

/**
 * bd_lvm_lvdata_free: (skip)
 *
 * Frees @data.
 */
void  bd_lvm_lvdata_free (BDLVMLVdata *data) {
        g_free (data->lv_name);
    g_free (data->vg_name);
    g_free (data->uuid);
    g_free (data->attr);
    g_free (data->segtype);
    g_free (data);
}

GType  bd_lvm_lvdata_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDLVMLVdata",
                                            (GBoxedCopyFunc) bd_lvm_lvdata_copy,
                                            (GBoxedFreeFunc) bd_lvm_lvdata_free);
    }

    return type;
}

/**
 * bd_lvm_cache_stats_copy: (skip)
 *
 * Creates a new copy of @data.
 */
BDLVMCacheStats* bd_lvm_cache_stats_copy (BDLVMCacheStats *data) {
        BDLVMCacheStats *new = g_new0 (BDLVMCacheStats, 1);

    new->block_size = data->block_size;
    new->cache_size = data->cache_size;
    new->cache_used = data->cache_used;
    new->md_block_size = data->md_block_size;
    new->md_size = data->md_size;
    new->md_used = data->md_used;
    new->read_hits = data->read_hits;
    new->read_misses = data->read_misses;
    new->write_hits = data->write_hits;
    new->write_misses = data->write_misses;
    new->mode = data->mode;

    return new;
}

/**
 * bd_lvm_cache_stats_free: (skip)
 *
 * Frees @data.
 */
void  bd_lvm_cache_stats_free (BDLVMLVdata *data) {
        g_free (data);
}

GType  bd_lvm_cache_stats_get_type () {
        static GType type = 0;

    if (G_UNLIKELY(type == 0)) {
        type = g_boxed_type_register_static("BDLVMCacheStats",
                                            (GBoxedCopyFunc) bd_lvm_cache_stats_copy,
                                            (GBoxedFreeFunc) bd_lvm_cache_stats_free);
    }

    return type;
}

static const gchar const * const lvm_functions[] = {
    "bd_lvm_is_supported_pe_size",
    "bd_lvm_get_supported_pe_sizes",
    "bd_lvm_get_max_lv_size",
    "bd_lvm_round_size_to_pe",
    "bd_lvm_get_lv_physical_size",
    "bd_lvm_get_thpool_padding",
    "bd_lvm_is_valid_thpool_md_size",
    "bd_lvm_is_valid_thpool_chunk_size",
    "bd_lvm_pvcreate",
    "bd_lvm_pvresize",
    "bd_lvm_pvremove",
    "bd_lvm_pvmove",
    "bd_lvm_pvscan",
    "bd_lvm_pvinfo",
    "bd_lvm_pvs",
    "bd_lvm_vgcreate",
    "bd_lvm_vgremove",
    "bd_lvm_vgrename",
    "bd_lvm_vgactivate",
    "bd_lvm_vgdeactivate",
    "bd_lvm_vgextend",
    "bd_lvm_vgreduce",
    "bd_lvm_vginfo",
    "bd_lvm_vgs",
    "bd_lvm_lvorigin",
    "bd_lvm_lvcreate",
    "bd_lvm_lvremove",
    "bd_lvm_lvrename",
    "bd_lvm_lvresize",
    "bd_lvm_lvactivate",
    "bd_lvm_lvdeactivate",
    "bd_lvm_lvsnapshotcreate",
    "bd_lvm_lvsnapshotmerge",
    "bd_lvm_lvinfo",
    "bd_lvm_lvs",
    "bd_lvm_thpoolcreate",
    "bd_lvm_thlvcreate",
    "bd_lvm_thlvpoolname",
    "bd_lvm_thsnapshotcreate",
    "bd_lvm_set_global_config",
    "bd_lvm_get_global_config",
    "bd_lvm_cache_get_default_md_size",
    "bd_lvm_cache_get_mode_str",
    "bd_lvm_cache_get_mode_from_str",
    "bd_lvm_cache_create_pool",
    "bd_lvm_cache_attach",
    "bd_lvm_cache_detach",
    "bd_lvm_cache_create_cached_lv",
    "bd_lvm_cache_pool_name",
    "bd_lvm_cache_stats",
    "bd_lvm_data_lv_name",
    "bd_lvm_metadata_lv_name",
    NULL};

gchar const * const * get_lvm_functions (void) {
    return lvm_functions;
}

static const guint8 lvm_num_functions = 52;

guint8 get_lvm_num_functions (void) {
    return lvm_num_functions;
}

gboolean  bd_lvm_is_supported_pe_size_stub (guint64 size, GError **error) {
    g_critical ("The function 'bd_lvm_is_supported_pe_size' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_is_supported_pe_size' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_is_supported_pe_size) (guint64 size, GError **error) = bd_lvm_is_supported_pe_size_stub;

/**
 * bd_lvm_is_supported_pe_size:
 * @size: size (in bytes) to test
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given size is supported physical extent size or not
 */
gboolean  bd_lvm_is_supported_pe_size (guint64 size, GError **error) {
    return _bd_lvm_is_supported_pe_size (size, error);
}


guint64 * bd_lvm_get_supported_pe_sizes_stub (GError **error) {
    g_critical ("The function 'bd_lvm_get_supported_pe_sizes' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_get_supported_pe_sizes' called, but not implemented!");
    return 0;
}

guint64 * (*_bd_lvm_get_supported_pe_sizes) (GError **error) = bd_lvm_get_supported_pe_sizes_stub;

/**
 * bd_lvm_get_supported_pe_sizes:
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full) (array zero-terminated=1): list of supported PE sizes
 */
guint64 * bd_lvm_get_supported_pe_sizes (GError **error) {
    return _bd_lvm_get_supported_pe_sizes (error);
}


guint64  bd_lvm_get_max_lv_size_stub (GError **error) {
    g_critical ("The function 'bd_lvm_get_max_lv_size' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_get_max_lv_size' called, but not implemented!");
    return 0;
}

guint64  (*_bd_lvm_get_max_lv_size) (GError **error) = bd_lvm_get_max_lv_size_stub;

/**
 * bd_lvm_get_max_lv_size:
 * @error: (out): place to store error (if any)
 *
 * Returns: maximum LV size in bytes
 */
guint64  bd_lvm_get_max_lv_size (GError **error) {
    return _bd_lvm_get_max_lv_size (error);
}


guint64  bd_lvm_round_size_to_pe_stub (guint64 size, guint64 pe_size, gboolean roundup, GError **error) {
    g_critical ("The function 'bd_lvm_round_size_to_pe' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_round_size_to_pe' called, but not implemented!");
    return 0;
}

guint64  (*_bd_lvm_round_size_to_pe) (guint64 size, guint64 pe_size, gboolean roundup, GError **error) = bd_lvm_round_size_to_pe_stub;

/**
 * bd_lvm_round_size_to_pe:
 * @size: size to be rounded
 * @pe_size: physical extent (PE) size or 0 to use the default
 * @roundup: whether to round up or down (ceil or floor)
 * @error: (out): place to store error (if any)
 *
 * Returns: @size rounded to @pe_size according to the @roundup
 *
 * Rounds given @size up/down to a multiple of @pe_size according to the value
 * of the @roundup parameter. If the rounded value is too big to fit in the
 * return type, the result is rounded down (floored) regardless of the @roundup
 * parameter.
 */
guint64  bd_lvm_round_size_to_pe (guint64 size, guint64 pe_size, gboolean roundup, GError **error) {
    return _bd_lvm_round_size_to_pe (size, pe_size, roundup, error);
}


guint64  bd_lvm_get_lv_physical_size_stub (guint64 lv_size, guint64 pe_size, GError **error) {
    g_critical ("The function 'bd_lvm_get_lv_physical_size' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_get_lv_physical_size' called, but not implemented!");
    return 0;
}

guint64  (*_bd_lvm_get_lv_physical_size) (guint64 lv_size, guint64 pe_size, GError **error) = bd_lvm_get_lv_physical_size_stub;

/**
 * bd_lvm_get_lv_physical_size:
 * @lv_size: LV size
 * @pe_size: PE size
 * @error: (out): place to store error (if any)
 *
 * Returns: space taken on disk(s) by the LV with given @size
 *
 * Gives number of bytes needed for an LV with the size @lv_size on an LVM stack
 * using given @pe_size.
 */
guint64  bd_lvm_get_lv_physical_size (guint64 lv_size, guint64 pe_size, GError **error) {
    return _bd_lvm_get_lv_physical_size (lv_size, pe_size, error);
}


guint64  bd_lvm_get_thpool_padding_stub (guint64 size, guint64 pe_size, gboolean included, GError **error) {
    g_critical ("The function 'bd_lvm_get_thpool_padding' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_get_thpool_padding' called, but not implemented!");
    return 0;
}

guint64  (*_bd_lvm_get_thpool_padding) (guint64 size, guint64 pe_size, gboolean included, GError **error) = bd_lvm_get_thpool_padding_stub;

/**
 * bd_lvm_get_thpool_padding:
 * @size: size of the thin pool
 * @pe_size: PE size or 0 if the default value should be used
 * @included: if padding is already included in the size
 * @error: (out): place to store error (if any)
 *
 * Returns: size of the padding needed for a thin pool with the given @size
 *         according to the @pe_size and @included
 */
guint64  bd_lvm_get_thpool_padding (guint64 size, guint64 pe_size, gboolean included, GError **error) {
    return _bd_lvm_get_thpool_padding (size, pe_size, included, error);
}


gboolean  bd_lvm_is_valid_thpool_md_size_stub (guint64 size, GError **error) {
    g_critical ("The function 'bd_lvm_is_valid_thpool_md_size' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_is_valid_thpool_md_size' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_is_valid_thpool_md_size) (guint64 size, GError **error) = bd_lvm_is_valid_thpool_md_size_stub;

/**
 * bd_lvm_is_valid_thpool_md_size:
 * @size: the size to be tested
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given size is a valid thin pool metadata size or not
 */
gboolean  bd_lvm_is_valid_thpool_md_size (guint64 size, GError **error) {
    return _bd_lvm_is_valid_thpool_md_size (size, error);
}


gboolean  bd_lvm_is_valid_thpool_chunk_size_stub (guint64 size, gboolean discard, GError **error) {
    g_critical ("The function 'bd_lvm_is_valid_thpool_chunk_size' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_is_valid_thpool_chunk_size' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_is_valid_thpool_chunk_size) (guint64 size, gboolean discard, GError **error) = bd_lvm_is_valid_thpool_chunk_size_stub;

/**
 * bd_lvm_is_valid_thpool_chunk_size:
 * @size: the size to be tested
 * @discard: whether discard/TRIM is required to be supported or not
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given size is a valid thin pool chunk size or not
 */
gboolean  bd_lvm_is_valid_thpool_chunk_size (guint64 size, gboolean discard, GError **error) {
    return _bd_lvm_is_valid_thpool_chunk_size (size, discard, error);
}


gboolean  bd_lvm_pvcreate_stub (gchar *device, guint64 data_alignment, guint64 metadata_size, GError **error) {
    g_critical ("The function 'bd_lvm_pvcreate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_pvcreate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_pvcreate) (gchar *device, guint64 data_alignment, guint64 metadata_size, GError **error) = bd_lvm_pvcreate_stub;

/**
 * bd_lvm_pvcreate:
 * @device: the device to make PV from
 * @data_alignment: data (first PE) alignment or 0 to use the default
 * @metadata_size: size of the area reserved for metadata or 0 to use the default
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the PV was successfully created or not
 */
gboolean  bd_lvm_pvcreate (gchar *device, guint64 data_alignment, guint64 metadata_size, GError **error) {
    return _bd_lvm_pvcreate (device, data_alignment, metadata_size, error);
}


gboolean  bd_lvm_pvresize_stub (gchar *device, guint64 size, GError **error) {
    g_critical ("The function 'bd_lvm_pvresize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_pvresize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_pvresize) (gchar *device, guint64 size, GError **error) = bd_lvm_pvresize_stub;

/**
 * bd_lvm_pvresize:
 * @device: the device to resize
 * @size: the new requested size of the PV or 0 if it should be adjusted to device's size
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the PV's size was successfully changed or not
 *
 * If given @size different from 0, sets the PV's size to the given value (see
 * pvresize(8)). If given @size 0, adjusts the PV's size to the underlaying
 * block device's size.
 */
gboolean  bd_lvm_pvresize (gchar *device, guint64 size, GError **error) {
    return _bd_lvm_pvresize (device, size, error);
}


gboolean  bd_lvm_pvremove_stub (gchar *device, GError **error) {
    g_critical ("The function 'bd_lvm_pvremove' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_pvremove' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_pvremove) (gchar *device, GError **error) = bd_lvm_pvremove_stub;

/**
 * bd_lvm_pvremove:
 * @device: the PV device to be removed/destroyed
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the PV was successfully removed/destroyed or not
 */
gboolean  bd_lvm_pvremove (gchar *device, GError **error) {
    return _bd_lvm_pvremove (device, error);
}


gboolean  bd_lvm_pvmove_stub (gchar *src, gchar *dest, GError **error) {
    g_critical ("The function 'bd_lvm_pvmove' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_pvmove' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_pvmove) (gchar *src, gchar *dest, GError **error) = bd_lvm_pvmove_stub;

/**
 * bd_lvm_pvmove:
 * @src: the PV device to move extents off of
 * @dest: (allow-none): the PV device to move extents onto or %NULL
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the extents from the @src PV where successfully moved or not
 *
 * If @dest is %NULL, VG allocation rules are used for the extents from the @src
 * PV (see pvmove(8)).
 */
gboolean  bd_lvm_pvmove (gchar *src, gchar *dest, GError **error) {
    return _bd_lvm_pvmove (src, dest, error);
}


gboolean  bd_lvm_pvscan_stub (gchar *device, gboolean update_cache, GError **error) {
    g_critical ("The function 'bd_lvm_pvscan' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_pvscan' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_pvscan) (gchar *device, gboolean update_cache, GError **error) = bd_lvm_pvscan_stub;

/**
 * bd_lvm_pvscan:
 * @device: (allow-none): the device to scan for PVs or %NULL
 * @update_cache: whether to update the lvmetad cache or not
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the system or @device was successfully scanned for PVs or not
 *
 * The @device argument is used only if @update_cache is %TRUE. Otherwise the
 * whole system is scanned for PVs.
 */
gboolean  bd_lvm_pvscan (gchar *device, gboolean update_cache, GError **error) {
    return _bd_lvm_pvscan (device, update_cache, error);
}


BDLVMPVdata* bd_lvm_pvinfo_stub (gchar *device, GError **error) {
    g_critical ("The function 'bd_lvm_pvinfo' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_pvinfo' called, but not implemented!");
    return NULL;
}

BDLVMPVdata* (*_bd_lvm_pvinfo) (gchar *device, GError **error) = bd_lvm_pvinfo_stub;

/**
 * bd_lvm_pvinfo:
 * @device: a PV to get information about or %NULL
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the PV on the given @device or
 * %NULL in case of error (the @error) gets populated in those cases)
 */
BDLVMPVdata* bd_lvm_pvinfo (gchar *device, GError **error) {
    return _bd_lvm_pvinfo (device, error);
}


BDLVMPVdata** bd_lvm_pvs_stub (GError **error) {
    g_critical ("The function 'bd_lvm_pvs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_pvs' called, but not implemented!");
    return NULL;
}

BDLVMPVdata** (*_bd_lvm_pvs) (GError **error) = bd_lvm_pvs_stub;

/**
 * bd_lvm_pvs:
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about PVs found in the system
 */
BDLVMPVdata** bd_lvm_pvs (GError **error) {
    return _bd_lvm_pvs (error);
}


gboolean  bd_lvm_vgcreate_stub (gchar *name, gchar **pv_list, guint64 pe_size, GError **error) {
    g_critical ("The function 'bd_lvm_vgcreate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_vgcreate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_vgcreate) (gchar *name, gchar **pv_list, guint64 pe_size, GError **error) = bd_lvm_vgcreate_stub;

/**
 * bd_lvm_vgcreate:
 * @name: name of the newly created VG
 * @pv_list: (array zero-terminated=1): list of PVs the newly created VG should use
 * @pe_size: PE size or 0 if the default value should be used
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG @name was successfully created or not
 */
gboolean  bd_lvm_vgcreate (gchar *name, gchar **pv_list, guint64 pe_size, GError **error) {
    return _bd_lvm_vgcreate (name, pv_list, pe_size, error);
}


gboolean  bd_lvm_vgremove_stub (gchar *vg_name, GError **error) {
    g_critical ("The function 'bd_lvm_vgremove' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_vgremove' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_vgremove) (gchar *vg_name, GError **error) = bd_lvm_vgremove_stub;

/**
 * bd_lvm_vgremove:
 * @vg_name: name of the to be removed VG
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG was successfully removed or not
 *
 * Note: forces the VG removal.
 */
gboolean  bd_lvm_vgremove (gchar *vg_name, GError **error) {
    return _bd_lvm_vgremove (vg_name, error);
}


gboolean  bd_lvm_vgrename_stub (gchar *old_vg_name, gchar *new_vg_name, GError **error) {
    g_critical ("The function 'bd_lvm_vgrename' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_vgrename' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_vgrename) (gchar *old_vg_name, gchar *new_vg_name, GError **error) = bd_lvm_vgrename_stub;

/**
 * bd_lvm_vgrename:
 * @old_vg_name: old name of the VG to rename
 * @new_vg_name: new name for the @old_vg_name VG
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG was successfully renamed or not
 */
gboolean  bd_lvm_vgrename (gchar *old_vg_name, gchar *new_vg_name, GError **error) {
    return _bd_lvm_vgrename (old_vg_name, new_vg_name, error);
}


gboolean  bd_lvm_vgactivate_stub (gchar *vg_name, GError **error) {
    g_critical ("The function 'bd_lvm_vgactivate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_vgactivate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_vgactivate) (gchar *vg_name, GError **error) = bd_lvm_vgactivate_stub;

/**
 * bd_lvm_vgactivate:
 * @vg_name: name of the to be activated VG
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG was successfully activated or not
 */
gboolean  bd_lvm_vgactivate (gchar *vg_name, GError **error) {
    return _bd_lvm_vgactivate (vg_name, error);
}


gboolean  bd_lvm_vgdeactivate_stub (gchar *vg_name, GError **error) {
    g_critical ("The function 'bd_lvm_vgdeactivate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_vgdeactivate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_vgdeactivate) (gchar *vg_name, GError **error) = bd_lvm_vgdeactivate_stub;

/**
 * bd_lvm_vgdeactivate:
 * @vg_name: name of the to be deactivated VG
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG was successfully deactivated or not
 */
gboolean  bd_lvm_vgdeactivate (gchar *vg_name, GError **error) {
    return _bd_lvm_vgdeactivate (vg_name, error);
}


gboolean  bd_lvm_vgextend_stub (gchar *vg_name, gchar *device, GError **error) {
    g_critical ("The function 'bd_lvm_vgextend' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_vgextend' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_vgextend) (gchar *vg_name, gchar *device, GError **error) = bd_lvm_vgextend_stub;

/**
 * bd_lvm_vgextend:
 * @vg_name: name of the to be extended VG
 * @device: PV device to extend the @vg_name VG with
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG @vg_name was successfully extended with the given @device or not.
 */
gboolean  bd_lvm_vgextend (gchar *vg_name, gchar *device, GError **error) {
    return _bd_lvm_vgextend (vg_name, device, error);
}


gboolean  bd_lvm_vgreduce_stub (gchar *vg_name, gchar *device, GError **error) {
    g_critical ("The function 'bd_lvm_vgreduce' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_vgreduce' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_vgreduce) (gchar *vg_name, gchar *device, GError **error) = bd_lvm_vgreduce_stub;

/**
 * bd_lvm_vgreduce:
 * @vg_name: name of the to be reduced VG
 * @device: (allow-none): PV device the @vg_name VG should be reduced of or %NULL
 *                        if the VG should be reduced of the missing PVs
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the VG @vg_name was successfully reduced of the given @device or not
 */
gboolean  bd_lvm_vgreduce (gchar *vg_name, gchar *device, GError **error) {
    return _bd_lvm_vgreduce (vg_name, device, error);
}


BDLVMVGdata* bd_lvm_vginfo_stub (gchar *vg_name, GError **error) {
    g_critical ("The function 'bd_lvm_vginfo' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_vginfo' called, but not implemented!");
    return NULL;
}

BDLVMVGdata* (*_bd_lvm_vginfo) (gchar *vg_name, GError **error) = bd_lvm_vginfo_stub;

/**
 * bd_lvm_vginfo:
 * @vg_name: a VG to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the @vg_name VG or %NULL in case
 * of error (the @error) gets populated in those cases)
 */
BDLVMVGdata* bd_lvm_vginfo (gchar *vg_name, GError **error) {
    return _bd_lvm_vginfo (vg_name, error);
}


BDLVMVGdata** bd_lvm_vgs_stub (GError **error) {
    g_critical ("The function 'bd_lvm_vgs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_vgs' called, but not implemented!");
    return NULL;
}

BDLVMVGdata** (*_bd_lvm_vgs) (GError **error) = bd_lvm_vgs_stub;

/**
 * bd_lvm_vgs:
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about VGs found in the system
 */
BDLVMVGdata** bd_lvm_vgs (GError **error) {
    return _bd_lvm_vgs (error);
}


gchar* bd_lvm_lvorigin_stub (gchar *vg_name, gchar *lv_name, GError **error) {
    g_critical ("The function 'bd_lvm_lvorigin' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvorigin' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_lvm_lvorigin) (gchar *vg_name, gchar *lv_name, GError **error) = bd_lvm_lvorigin_stub;

/**
 * bd_lvm_lvorigin:
 * @vg_name: name of the VG containing the queried LV
 * @lv_name: name of the queried LV
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): the origin volume for the @vg_name/@lv_name LV or
 * %NULL if failed to determine (@error) is set in those cases)
 */
gchar* bd_lvm_lvorigin (gchar *vg_name, gchar *lv_name, GError **error) {
    return _bd_lvm_lvorigin (vg_name, lv_name, error);
}


gboolean  bd_lvm_lvcreate_stub (gchar *vg_name, gchar *lv_name, guint64 size, gchar *type, gchar **pv_list, GError **error) {
    g_critical ("The function 'bd_lvm_lvcreate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvcreate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_lvcreate) (gchar *vg_name, gchar *lv_name, guint64 size, gchar *type, gchar **pv_list, GError **error) = bd_lvm_lvcreate_stub;

/**
 * bd_lvm_lvcreate:
 * @vg_name: name of the VG to create a new LV in
 * @lv_name: name of the to-be-created LV
 * @size: requested size of the new LV
 * @type: (allow-none): type of the new LV ("striped", "raid1",..., see lvcreate (8))
 * @pv_list: (allow-none) (array zero-terminated=1): list of PVs the newly created LV should use or %NULL
 * if not specified
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the given @vg_name/@lv_name LV was successfully created or not
 */
gboolean  bd_lvm_lvcreate (gchar *vg_name, gchar *lv_name, guint64 size, gchar *type, gchar **pv_list, GError **error) {
    return _bd_lvm_lvcreate (vg_name, lv_name, size, type, pv_list, error);
}


gboolean  bd_lvm_lvremove_stub (gchar *vg_name, gchar *lv_name, gboolean force, GError **error) {
    g_critical ("The function 'bd_lvm_lvremove' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvremove' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_lvremove) (gchar *vg_name, gchar *lv_name, gboolean force, GError **error) = bd_lvm_lvremove_stub;

/**
 * bd_lvm_lvremove:
 * @vg_name: name of the VG containing the to-be-removed LV
 * @lv_name: name of the to-be-removed LV
 * @force: whether to force removal or not
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully removed or not
 */
gboolean  bd_lvm_lvremove (gchar *vg_name, gchar *lv_name, gboolean force, GError **error) {
    return _bd_lvm_lvremove (vg_name, lv_name, force, error);
}


gboolean  bd_lvm_lvrename_stub (gchar *vg_name, gchar *lv_name, gchar *new_name, GError **error) {
    g_critical ("The function 'bd_lvm_lvrename' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvrename' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_lvrename) (gchar *vg_name, gchar *lv_name, gchar *new_name, GError **error) = bd_lvm_lvrename_stub;

/**
 * bd_lvm_lvrename:
 * @vg_name: name of the VG containing the to-be-renamed LV
 * @lv_name: name of the to-be-renamed LV
 * @new_name: new name for the @vg_name/@lv_name LV
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully renamed to
 * @vg_name/@new_name or not
 */
gboolean  bd_lvm_lvrename (gchar *vg_name, gchar *lv_name, gchar *new_name, GError **error) {
    return _bd_lvm_lvrename (vg_name, lv_name, new_name, error);
}


gboolean  bd_lvm_lvresize_stub (gchar *vg_name, gchar *lv_name, guint64 size, GError **error) {
    g_critical ("The function 'bd_lvm_lvresize' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvresize' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_lvresize) (gchar *vg_name, gchar *lv_name, guint64 size, GError **error) = bd_lvm_lvresize_stub;

/**
 * bd_lvm_lvresize:
 * @vg_name: name of the VG containing the to-be-resized LV
 * @lv_name: name of the to-be-resized LV
 * @size: the requested new size of the LV
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully resized or not
 */
gboolean  bd_lvm_lvresize (gchar *vg_name, gchar *lv_name, guint64 size, GError **error) {
    return _bd_lvm_lvresize (vg_name, lv_name, size, error);
}


gboolean  bd_lvm_lvactivate_stub (gchar *vg_name, gchar *lv_name, gboolean ignore_skip, GError **error) {
    g_critical ("The function 'bd_lvm_lvactivate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvactivate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_lvactivate) (gchar *vg_name, gchar *lv_name, gboolean ignore_skip, GError **error) = bd_lvm_lvactivate_stub;

/**
 * bd_lvm_lvactivate:
 * @vg_name: name of the VG containing the to-be-activated LV
 * @lv_name: name of the to-be-activated LV
 * @ignore_skip: whether to ignore the skip flag or not
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully activated or not
 */
gboolean  bd_lvm_lvactivate (gchar *vg_name, gchar *lv_name, gboolean ignore_skip, GError **error) {
    return _bd_lvm_lvactivate (vg_name, lv_name, ignore_skip, error);
}


gboolean  bd_lvm_lvdeactivate_stub (gchar *vg_name, gchar *lv_name, GError **error) {
    g_critical ("The function 'bd_lvm_lvdeactivate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvdeactivate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_lvdeactivate) (gchar *vg_name, gchar *lv_name, GError **error) = bd_lvm_lvdeactivate_stub;

/**
 * bd_lvm_lvdeactivate:
 * @vg_name: name of the VG containing the to-be-deactivated LV
 * @lv_name: name of the to-be-deactivated LV
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name LV was successfully deactivated or not
 */
gboolean  bd_lvm_lvdeactivate (gchar *vg_name, gchar *lv_name, GError **error) {
    return _bd_lvm_lvdeactivate (vg_name, lv_name, error);
}


gboolean  bd_lvm_lvsnapshotcreate_stub (gchar *vg_name, gchar *origin_name, gchar *snapshot_name, guint64 size, GError **error) {
    g_critical ("The function 'bd_lvm_lvsnapshotcreate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvsnapshotcreate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_lvsnapshotcreate) (gchar *vg_name, gchar *origin_name, gchar *snapshot_name, guint64 size, GError **error) = bd_lvm_lvsnapshotcreate_stub;

/**
 * bd_lvm_lvsnapshotcreate:
 * @vg_name: name of the VG containing the LV a new snapshot should be created of
 * @origin_name: name of the LV a new snapshot should be created of
 * @snapshot_name: name fo the to-be-created snapshot
 * @size: requested size for the snapshot
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @snapshot_name snapshot of the @vg_name/@origin_name LV
 * was successfully created or not.
 */
gboolean  bd_lvm_lvsnapshotcreate (gchar *vg_name, gchar *origin_name, gchar *snapshot_name, guint64 size, GError **error) {
    return _bd_lvm_lvsnapshotcreate (vg_name, origin_name, snapshot_name, size, error);
}


gboolean  bd_lvm_lvsnapshotmerge_stub (gchar *vg_name, gchar *snapshot_name, GError **error) {
    g_critical ("The function 'bd_lvm_lvsnapshotmerge' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvsnapshotmerge' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_lvsnapshotmerge) (gchar *vg_name, gchar *snapshot_name, GError **error) = bd_lvm_lvsnapshotmerge_stub;

/**
 * bd_lvm_lvsnapshotmerge:
 * @vg_name: name of the VG containing the to-be-merged LV snapshot
 * @snapshot_name: name of the to-be-merged LV snapshot
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@snapshot_name LV snapshot was successfully merged or not
 */
gboolean  bd_lvm_lvsnapshotmerge (gchar *vg_name, gchar *snapshot_name, GError **error) {
    return _bd_lvm_lvsnapshotmerge (vg_name, snapshot_name, error);
}


BDLVMLVdata* bd_lvm_lvinfo_stub (gchar *vg_name, gchar *lv_name, GError **error) {
    g_critical ("The function 'bd_lvm_lvinfo' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvinfo' called, but not implemented!");
    return NULL;
}

BDLVMLVdata* (*_bd_lvm_lvinfo) (gchar *vg_name, gchar *lv_name, GError **error) = bd_lvm_lvinfo_stub;

/**
 * bd_lvm_lvinfo:
 * @vg_name: name of the VG that contains the LV to get information about
 * @lv_name: name of the LV to get information about
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): information about the @vg_name/@lv_name LV or %NULL in case
 * of error (the @error) gets populated in those cases)
 */
BDLVMLVdata* bd_lvm_lvinfo (gchar *vg_name, gchar *lv_name, GError **error) {
    return _bd_lvm_lvinfo (vg_name, lv_name, error);
}


BDLVMLVdata** bd_lvm_lvs_stub (gchar *vg_name, GError **error) {
    g_critical ("The function 'bd_lvm_lvs' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_lvs' called, but not implemented!");
    return NULL;
}

BDLVMLVdata** (*_bd_lvm_lvs) (gchar *vg_name, GError **error) = bd_lvm_lvs_stub;

/**
 * bd_lvm_lvs:
 * @vg_name: (allow-none): name of the VG to get information about LVs from
 * @error: (out): place to store error (if any)
 *
 * Returns: (array zero-terminated=1): information about LVs found in the given
 * @vg_name VG or in system if @vg_name is %NULL
 */
BDLVMLVdata** bd_lvm_lvs (gchar *vg_name, GError **error) {
    return _bd_lvm_lvs (vg_name, error);
}


gboolean  bd_lvm_thpoolcreate_stub (gchar *vg_name, gchar *lv_name, guint64 size, guint64 md_size, guint64 chunk_size, gchar *profile, GError **error) {
    g_critical ("The function 'bd_lvm_thpoolcreate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_thpoolcreate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_thpoolcreate) (gchar *vg_name, gchar *lv_name, guint64 size, guint64 md_size, guint64 chunk_size, gchar *profile, GError **error) = bd_lvm_thpoolcreate_stub;

/**
 * bd_lvm_thpoolcreate:
 * @vg_name: name of the VG to create a thin pool in
 * @lv_name: name of the to-be-created pool LV
 * @size: requested size of the to-be-created pool
 * @md_size: requested metadata size or 0 to use the default
 * @chunk_size: requested chunk size or 0 to use the default
 * @profile: (allow-none): profile to use (see lvm(8) for more information) or %NULL to use
 *                         the default
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name thin pool was successfully created or not
 */
gboolean  bd_lvm_thpoolcreate (gchar *vg_name, gchar *lv_name, guint64 size, guint64 md_size, guint64 chunk_size, gchar *profile, GError **error) {
    return _bd_lvm_thpoolcreate (vg_name, lv_name, size, md_size, chunk_size, profile, error);
}


gboolean  bd_lvm_thlvcreate_stub (gchar *vg_name, gchar *pool_name, gchar *lv_name, guint64 size, GError **error) {
    g_critical ("The function 'bd_lvm_thlvcreate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_thlvcreate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_thlvcreate) (gchar *vg_name, gchar *pool_name, gchar *lv_name, guint64 size, GError **error) = bd_lvm_thlvcreate_stub;

/**
 * bd_lvm_thlvcreate:
 * @vg_name: name of the VG containing the thin pool providing extents for the to-be-created thin LV
 * @pool_name: name of the pool LV providing extents for the to-be-created thin LV
 * @lv_name: name of the to-be-created thin LV
 * @size: requested virtual size of the to-be-created thin LV
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @vg_name/@lv_name thin LV was successfully created or not
 */
gboolean  bd_lvm_thlvcreate (gchar *vg_name, gchar *pool_name, gchar *lv_name, guint64 size, GError **error) {
    return _bd_lvm_thlvcreate (vg_name, pool_name, lv_name, size, error);
}


gchar* bd_lvm_thlvpoolname_stub (gchar *vg_name, gchar *lv_name, GError **error) {
    g_critical ("The function 'bd_lvm_thlvpoolname' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_thlvpoolname' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_lvm_thlvpoolname) (gchar *vg_name, gchar *lv_name, GError **error) = bd_lvm_thlvpoolname_stub;

/**
 * bd_lvm_thlvpoolname:
 * @vg_name: name of the VG containing the queried thin LV
 * @lv_name: name of the queried thin LV
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): the name of the pool volume for the @vg_name/@lv_name
 * thin LV or %NULL if failed to determine (@error) is set in those cases)
 */
gchar* bd_lvm_thlvpoolname (gchar *vg_name, gchar *lv_name, GError **error) {
    return _bd_lvm_thlvpoolname (vg_name, lv_name, error);
}


gboolean  bd_lvm_thsnapshotcreate_stub (gchar *vg_name, gchar *origin_name, gchar *snapshot_name, gchar *pool_name, GError **error) {
    g_critical ("The function 'bd_lvm_thsnapshotcreate' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_thsnapshotcreate' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_thsnapshotcreate) (gchar *vg_name, gchar *origin_name, gchar *snapshot_name, gchar *pool_name, GError **error) = bd_lvm_thsnapshotcreate_stub;

/**
 * bd_lvm_thsnapshotcreate:
 * @vg_name: name of the VG containing the thin LV a new snapshot should be created of
 * @origin_name: name of the thin LV a new snapshot should be created of
 * @snapshot_name: name fo the to-be-created snapshot
 * @pool_name: (allow-none): name of the thin pool to create the snapshot in or %NULL if not specified
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @snapshot_name snapshot of the @vg_name/@origin_name
 * thin LV was successfully created or not.
 */
gboolean  bd_lvm_thsnapshotcreate (gchar *vg_name, gchar *origin_name, gchar *snapshot_name, gchar *pool_name, GError **error) {
    return _bd_lvm_thsnapshotcreate (vg_name, origin_name, snapshot_name, pool_name, error);
}


gboolean  bd_lvm_set_global_config_stub (gchar *new_config, GError **error) {
    g_critical ("The function 'bd_lvm_set_global_config' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_set_global_config' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_set_global_config) (gchar *new_config, GError **error) = bd_lvm_set_global_config_stub;

/**
 * bd_lvm_set_global_config:
 * @new_config: (allow-none): string representation of the new global LVM
 *                            configuration to set or %NULL to reset to default
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the new requested global config @new_config was successfully
 *          set or not
 */
gboolean  bd_lvm_set_global_config (gchar *new_config, GError **error) {
    return _bd_lvm_set_global_config (new_config, error);
}


gchar* bd_lvm_get_global_config_stub (GError **error) {
    g_critical ("The function 'bd_lvm_get_global_config' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_get_global_config' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_lvm_get_global_config) (GError **error) = bd_lvm_get_global_config_stub;

/**
 * bd_lvm_get_global_config:
 * @error: (out): place to store error (if any)
 *
 * Returns: a copy of a string representation of the currently set LVM global
 *          configuration
 */
gchar* bd_lvm_get_global_config (GError **error) {
    return _bd_lvm_get_global_config (error);
}


guint64  bd_lvm_cache_get_default_md_size_stub (guint64 cache_size, GError **error) {
    g_critical ("The function 'bd_lvm_cache_get_default_md_size' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_cache_get_default_md_size' called, but not implemented!");
    return 0;
}

guint64  (*_bd_lvm_cache_get_default_md_size) (guint64 cache_size, GError **error) = bd_lvm_cache_get_default_md_size_stub;

/**
 * bd_lvm_cache_get_default_md_size:
 * @cache_size: size of the cache to determine MD size for
 * @error: (out): place to store error (if any)
 *
 * Returns: recommended default size of the cache metadata LV or 0 in case of error
 */
guint64  bd_lvm_cache_get_default_md_size (guint64 cache_size, GError **error) {
    return _bd_lvm_cache_get_default_md_size (cache_size, error);
}


const gchar* bd_lvm_cache_get_mode_str_stub (BDLVMCacheMode mode, GError **error) {
    g_critical ("The function 'bd_lvm_cache_get_mode_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_cache_get_mode_str' called, but not implemented!");
    return NULL;
}

const gchar* (*_bd_lvm_cache_get_mode_str) (BDLVMCacheMode mode, GError **error) = bd_lvm_cache_get_mode_str_stub;

/**
 * bd_lvm_cache_get_mode_str:
 * @mode: mode to get the string representation for
 * @error: (out): place to store error (if any)
 *
 * Returns: string representation of @mode or %NULL in case of error
 */
const gchar* bd_lvm_cache_get_mode_str (BDLVMCacheMode mode, GError **error) {
    return _bd_lvm_cache_get_mode_str (mode, error);
}


BDLVMCacheMode  bd_lvm_cache_get_mode_from_str_stub (gchar *mode_str, GError **error) {
    g_critical ("The function 'bd_lvm_cache_get_mode_from_str' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_cache_get_mode_from_str' called, but not implemented!");
    return 0;
}

BDLVMCacheMode  (*_bd_lvm_cache_get_mode_from_str) (gchar *mode_str, GError **error) = bd_lvm_cache_get_mode_from_str_stub;

/**
 * bd_lvm_cache_get_mode_from_str:
 * @mode_str: string representation of a cache mode
 * @error: (out): place to store error (if any)
 *
 * Returns: cache mode for the @mode_str or %BD_LVM_CACHE_MODE_UNKNOWN if
 *          failed to determine
 */
BDLVMCacheMode  bd_lvm_cache_get_mode_from_str (gchar *mode_str, GError **error) {
    return _bd_lvm_cache_get_mode_from_str (mode_str, error);
}


gboolean  bd_lvm_cache_create_pool_stub (gchar *vg_name, gchar *pool_name, guint64 pool_size, guint64 md_size, BDLVMCacheMode mode, BDLVMCachePoolFlags flags, gchar **fast_pvs, GError **error) {
    g_critical ("The function 'bd_lvm_cache_create_pool' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_cache_create_pool' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_cache_create_pool) (gchar *vg_name, gchar *pool_name, guint64 pool_size, guint64 md_size, BDLVMCacheMode mode, BDLVMCachePoolFlags flags, gchar **fast_pvs, GError **error) = bd_lvm_cache_create_pool_stub;

/**
 * bd_lvm_cache_create_pool:
 * @vg_name: name of the VG to create @pool_name in
 * @pool_name: name of the cache pool LV to create
 * @pool_size: desired size of the cache pool @pool_name
 * @md_size: desired size of the @pool_name cache pool's metadata LV or 0 to
 *           use the default
 * @mode: cache mode of the @pool_name cache pool
 * @flags: a combination of (ORed) #BDLVMCachePoolFlags
 * @fast_pvs: (array zero-terminated=1): list of (fast) PVs to create the @pool_name
 *                                       cache pool (and the metadata LV)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the cache pool @vg_name/@pool_name was successfully created or not
 */
gboolean  bd_lvm_cache_create_pool (gchar *vg_name, gchar *pool_name, guint64 pool_size, guint64 md_size, BDLVMCacheMode mode, BDLVMCachePoolFlags flags, gchar **fast_pvs, GError **error) {
    return _bd_lvm_cache_create_pool (vg_name, pool_name, pool_size, md_size, mode, flags, fast_pvs, error);
}


gboolean  bd_lvm_cache_attach_stub (gchar *vg_name, gchar *data_lv, gchar *cache_pool_lv, GError **error) {
    g_critical ("The function 'bd_lvm_cache_attach' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_cache_attach' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_cache_attach) (gchar *vg_name, gchar *data_lv, gchar *cache_pool_lv, GError **error) = bd_lvm_cache_attach_stub;

/**
 * bd_lvm_cache_attach:
 * @vg_name: name of the VG containing the @data_lv and the @cache_pool_lv LVs
 * @data_lv: data LV to attache the @cache_pool_lv to
 * @cache_pool_lv: cache pool LV to attach to the @data_lv
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the @cache_pool_lv was successfully attached to the @data_lv or not
 */
gboolean  bd_lvm_cache_attach (gchar *vg_name, gchar *data_lv, gchar *cache_pool_lv, GError **error) {
    return _bd_lvm_cache_attach (vg_name, data_lv, cache_pool_lv, error);
}


gboolean  bd_lvm_cache_detach_stub (gchar *vg_name, gchar *cached_lv, gboolean destroy, GError **error) {
    g_critical ("The function 'bd_lvm_cache_detach' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_cache_detach' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_cache_detach) (gchar *vg_name, gchar *cached_lv, gboolean destroy, GError **error) = bd_lvm_cache_detach_stub;

/**
 * bd_lvm_cache_detach:
 * @vg_name: name of the VG containing the @cached_lv
 * @cached_lv: name of the cached LV to detach its cache from
 * @destroy: whether to destroy the cache after detach or not
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the cache was successfully detached from the @cached_lv or not
 *
 * Note: synces the cache first
 */
gboolean  bd_lvm_cache_detach (gchar *vg_name, gchar *cached_lv, gboolean destroy, GError **error) {
    return _bd_lvm_cache_detach (vg_name, cached_lv, destroy, error);
}


gboolean  bd_lvm_cache_create_cached_lv_stub (gchar *vg_name, gchar *lv_name, guint64 data_size, guint64 cache_size, guint64 md_size, BDLVMCacheMode mode, BDLVMCachePoolFlags flags, gchar **slow_pvs, gchar **fast_pvs, GError **error) {
    g_critical ("The function 'bd_lvm_cache_create_cached_lv' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_cache_create_cached_lv' called, but not implemented!");
    return FALSE;
}

gboolean  (*_bd_lvm_cache_create_cached_lv) (gchar *vg_name, gchar *lv_name, guint64 data_size, guint64 cache_size, guint64 md_size, BDLVMCacheMode mode, BDLVMCachePoolFlags flags, gchar **slow_pvs, gchar **fast_pvs, GError **error) = bd_lvm_cache_create_cached_lv_stub;

/**
 * bd_lvm_cache_create_cached_lv:
 * @vg_name: name of the VG to create a cached LV in
 * @lv_name: name of the cached LV to create
 * @data_size: size of the data LV
 * @cache_size: size of the cache (or cached LV more precisely)
 * @md_size: size of the cache metadata LV or 0 to use the default
 * @mode: cache mode for the cached LV
 * @flags: a combination of (ORed) #BDLVMCachePoolFlags
 * @slow_pvs: (array zero-terminated=1): list of slow PVs (used for the data LV)
 * @fast_pvs: (array zero-terminated=1): list of fast PVs (used for the cache LV)
 * @error: (out): place to store error (if any)
 *
 * Returns: whether the cached LV @lv_name was successfully created or not
 */
gboolean  bd_lvm_cache_create_cached_lv (gchar *vg_name, gchar *lv_name, guint64 data_size, guint64 cache_size, guint64 md_size, BDLVMCacheMode mode, BDLVMCachePoolFlags flags, gchar **slow_pvs, gchar **fast_pvs, GError **error) {
    return _bd_lvm_cache_create_cached_lv (vg_name, lv_name, data_size, cache_size, md_size, mode, flags, slow_pvs, fast_pvs, error);
}


gchar* bd_lvm_cache_pool_name_stub (gchar *vg_name, gchar *cached_lv, GError **error) {
    g_critical ("The function 'bd_lvm_cache_pool_name' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_cache_pool_name' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_lvm_cache_pool_name) (gchar *vg_name, gchar *cached_lv, GError **error) = bd_lvm_cache_pool_name_stub;

/**
 * bd_lvm_cache_pool_name:
 * @vg_name: name of the VG containing the @cached_lv
 * @cached_lv: cached LV to get the name of the its pool LV for
 * @error: (out): place to store error (if any)
 *
 * Returns: name of the cache pool LV used by the @cached_lv or %NULL in case of error
 */
gchar* bd_lvm_cache_pool_name (gchar *vg_name, gchar *cached_lv, GError **error) {
    return _bd_lvm_cache_pool_name (vg_name, cached_lv, error);
}


BDLVMCacheStats* bd_lvm_cache_stats_stub (gchar *vg_name, gchar *cached_lv, GError **error) {
    g_critical ("The function 'bd_lvm_cache_stats' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_cache_stats' called, but not implemented!");
    return NULL;
}

BDLVMCacheStats* (*_bd_lvm_cache_stats) (gchar *vg_name, gchar *cached_lv, GError **error) = bd_lvm_cache_stats_stub;

/**
 * bd_lvm_cache_stats:
 * @vg_name: name of the VG containing the @cached_lv
 * @cached_lv: cached LV to get stats for
 * @error: (out): place to store error (if any)
 *
 * Returns: stats for the @cached_lv or %NULL in case of error
 */
BDLVMCacheStats* bd_lvm_cache_stats (gchar *vg_name, gchar *cached_lv, GError **error) {
    return _bd_lvm_cache_stats (vg_name, cached_lv, error);
}


gchar* bd_lvm_data_lv_name_stub (gchar *vg_name, gchar *lv_name, GError **error) {
    g_critical ("The function 'bd_lvm_data_lv_name' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_data_lv_name' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_lvm_data_lv_name) (gchar *vg_name, gchar *lv_name, GError **error) = bd_lvm_data_lv_name_stub;

/**
 * bd_lvm_data_lv_name:
 * @vg_name: name of the VG containing the queried LV
 * @lv_name: name of the queried LV
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): the name of the (internal) data LV of the
 * @vg_name/@lv_name LV
 */
gchar* bd_lvm_data_lv_name (gchar *vg_name, gchar *lv_name, GError **error) {
    return _bd_lvm_data_lv_name (vg_name, lv_name, error);
}


gchar* bd_lvm_metadata_lv_name_stub (gchar *vg_name, gchar *lv_name, GError **error) {
    g_critical ("The function 'bd_lvm_metadata_lv_name' called, but not implemented!");
    g_set_error (error, BD_INIT_ERROR, BD_INIT_ERROR_NOT_IMPLEMENTED,
                "The function 'bd_lvm_metadata_lv_name' called, but not implemented!");
    return NULL;
}

gchar* (*_bd_lvm_metadata_lv_name) (gchar *vg_name, gchar *lv_name, GError **error) = bd_lvm_metadata_lv_name_stub;

/**
 * bd_lvm_metadata_lv_name:
 * @vg_name: name of the VG containing the queried LV
 * @lv_name: name of the queried LV
 * @error: (out): place to store error (if any)
 *
 * Returns: (transfer full): the name of the (internal) metadata LV of the
 * @vg_name/@lv_name LV
 */
gchar* bd_lvm_metadata_lv_name (gchar *vg_name, gchar *lv_name, GError **error) {
    return _bd_lvm_metadata_lv_name (vg_name, lv_name, error);
}


gpointer load_lvm_from_plugin(gchar *so_name) {
    void *handle = NULL;
    char *error = NULL;
    gboolean (*check_fn) (void) = NULL;
    gboolean (*init_fn) (void) = NULL;

    handle = dlopen(so_name, RTLD_LAZY);
    if (!handle) {
        g_warning("failed to load module lvm: %s", dlerror());
        return NULL;
    }

    dlerror();
    * (void**) (&check_fn) = dlsym(handle, "check");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the check() function for lvm: %s", error);
    if (check_fn && !check_fn()) {
        dlclose(handle);
        return NULL;
    }    check_fn = NULL;

    dlerror();
    * (void**) (&init_fn) = dlsym(handle, "init");
    if ((error = dlerror()) != NULL)
        g_debug("failed to load the init() function for lvm: %s", error);
    if (init_fn && !init_fn()) {
        dlclose(handle);
        return NULL;
    }    init_fn = NULL;

    dlerror();
    * (void**) (&_bd_lvm_is_supported_pe_size) = dlsym(handle, "bd_lvm_is_supported_pe_size");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_is_supported_pe_size: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_get_supported_pe_sizes) = dlsym(handle, "bd_lvm_get_supported_pe_sizes");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_get_supported_pe_sizes: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_get_max_lv_size) = dlsym(handle, "bd_lvm_get_max_lv_size");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_get_max_lv_size: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_round_size_to_pe) = dlsym(handle, "bd_lvm_round_size_to_pe");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_round_size_to_pe: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_get_lv_physical_size) = dlsym(handle, "bd_lvm_get_lv_physical_size");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_get_lv_physical_size: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_get_thpool_padding) = dlsym(handle, "bd_lvm_get_thpool_padding");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_get_thpool_padding: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_is_valid_thpool_md_size) = dlsym(handle, "bd_lvm_is_valid_thpool_md_size");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_is_valid_thpool_md_size: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_is_valid_thpool_chunk_size) = dlsym(handle, "bd_lvm_is_valid_thpool_chunk_size");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_is_valid_thpool_chunk_size: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_pvcreate) = dlsym(handle, "bd_lvm_pvcreate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_pvcreate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_pvresize) = dlsym(handle, "bd_lvm_pvresize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_pvresize: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_pvremove) = dlsym(handle, "bd_lvm_pvremove");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_pvremove: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_pvmove) = dlsym(handle, "bd_lvm_pvmove");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_pvmove: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_pvscan) = dlsym(handle, "bd_lvm_pvscan");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_pvscan: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_pvinfo) = dlsym(handle, "bd_lvm_pvinfo");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_pvinfo: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_pvs) = dlsym(handle, "bd_lvm_pvs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_pvs: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_vgcreate) = dlsym(handle, "bd_lvm_vgcreate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_vgcreate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_vgremove) = dlsym(handle, "bd_lvm_vgremove");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_vgremove: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_vgrename) = dlsym(handle, "bd_lvm_vgrename");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_vgrename: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_vgactivate) = dlsym(handle, "bd_lvm_vgactivate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_vgactivate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_vgdeactivate) = dlsym(handle, "bd_lvm_vgdeactivate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_vgdeactivate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_vgextend) = dlsym(handle, "bd_lvm_vgextend");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_vgextend: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_vgreduce) = dlsym(handle, "bd_lvm_vgreduce");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_vgreduce: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_vginfo) = dlsym(handle, "bd_lvm_vginfo");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_vginfo: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_vgs) = dlsym(handle, "bd_lvm_vgs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_vgs: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvorigin) = dlsym(handle, "bd_lvm_lvorigin");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvorigin: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvcreate) = dlsym(handle, "bd_lvm_lvcreate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvcreate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvremove) = dlsym(handle, "bd_lvm_lvremove");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvremove: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvrename) = dlsym(handle, "bd_lvm_lvrename");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvrename: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvresize) = dlsym(handle, "bd_lvm_lvresize");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvresize: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvactivate) = dlsym(handle, "bd_lvm_lvactivate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvactivate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvdeactivate) = dlsym(handle, "bd_lvm_lvdeactivate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvdeactivate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvsnapshotcreate) = dlsym(handle, "bd_lvm_lvsnapshotcreate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvsnapshotcreate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvsnapshotmerge) = dlsym(handle, "bd_lvm_lvsnapshotmerge");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvsnapshotmerge: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvinfo) = dlsym(handle, "bd_lvm_lvinfo");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvinfo: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_lvs) = dlsym(handle, "bd_lvm_lvs");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_lvs: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_thpoolcreate) = dlsym(handle, "bd_lvm_thpoolcreate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_thpoolcreate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_thlvcreate) = dlsym(handle, "bd_lvm_thlvcreate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_thlvcreate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_thlvpoolname) = dlsym(handle, "bd_lvm_thlvpoolname");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_thlvpoolname: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_thsnapshotcreate) = dlsym(handle, "bd_lvm_thsnapshotcreate");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_thsnapshotcreate: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_set_global_config) = dlsym(handle, "bd_lvm_set_global_config");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_set_global_config: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_get_global_config) = dlsym(handle, "bd_lvm_get_global_config");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_get_global_config: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_cache_get_default_md_size) = dlsym(handle, "bd_lvm_cache_get_default_md_size");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_cache_get_default_md_size: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_cache_get_mode_str) = dlsym(handle, "bd_lvm_cache_get_mode_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_cache_get_mode_str: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_cache_get_mode_from_str) = dlsym(handle, "bd_lvm_cache_get_mode_from_str");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_cache_get_mode_from_str: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_cache_create_pool) = dlsym(handle, "bd_lvm_cache_create_pool");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_cache_create_pool: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_cache_attach) = dlsym(handle, "bd_lvm_cache_attach");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_cache_attach: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_cache_detach) = dlsym(handle, "bd_lvm_cache_detach");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_cache_detach: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_cache_create_cached_lv) = dlsym(handle, "bd_lvm_cache_create_cached_lv");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_cache_create_cached_lv: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_cache_pool_name) = dlsym(handle, "bd_lvm_cache_pool_name");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_cache_pool_name: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_cache_stats) = dlsym(handle, "bd_lvm_cache_stats");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_cache_stats: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_data_lv_name) = dlsym(handle, "bd_lvm_data_lv_name");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_data_lv_name: %s", error);

    dlerror();
    * (void**) (&_bd_lvm_metadata_lv_name) = dlsym(handle, "bd_lvm_metadata_lv_name");
    if ((error = dlerror()) != NULL)
        g_warning("failed to load bd_lvm_metadata_lv_name: %s", error);

    return handle;
}

gboolean unload_lvm (gpointer handle) {
    _bd_lvm_is_supported_pe_size = bd_lvm_is_supported_pe_size_stub;
    _bd_lvm_get_supported_pe_sizes = bd_lvm_get_supported_pe_sizes_stub;
    _bd_lvm_get_max_lv_size = bd_lvm_get_max_lv_size_stub;
    _bd_lvm_round_size_to_pe = bd_lvm_round_size_to_pe_stub;
    _bd_lvm_get_lv_physical_size = bd_lvm_get_lv_physical_size_stub;
    _bd_lvm_get_thpool_padding = bd_lvm_get_thpool_padding_stub;
    _bd_lvm_is_valid_thpool_md_size = bd_lvm_is_valid_thpool_md_size_stub;
    _bd_lvm_is_valid_thpool_chunk_size = bd_lvm_is_valid_thpool_chunk_size_stub;
    _bd_lvm_pvcreate = bd_lvm_pvcreate_stub;
    _bd_lvm_pvresize = bd_lvm_pvresize_stub;
    _bd_lvm_pvremove = bd_lvm_pvremove_stub;
    _bd_lvm_pvmove = bd_lvm_pvmove_stub;
    _bd_lvm_pvscan = bd_lvm_pvscan_stub;
    _bd_lvm_pvinfo = bd_lvm_pvinfo_stub;
    _bd_lvm_pvs = bd_lvm_pvs_stub;
    _bd_lvm_vgcreate = bd_lvm_vgcreate_stub;
    _bd_lvm_vgremove = bd_lvm_vgremove_stub;
    _bd_lvm_vgrename = bd_lvm_vgrename_stub;
    _bd_lvm_vgactivate = bd_lvm_vgactivate_stub;
    _bd_lvm_vgdeactivate = bd_lvm_vgdeactivate_stub;
    _bd_lvm_vgextend = bd_lvm_vgextend_stub;
    _bd_lvm_vgreduce = bd_lvm_vgreduce_stub;
    _bd_lvm_vginfo = bd_lvm_vginfo_stub;
    _bd_lvm_vgs = bd_lvm_vgs_stub;
    _bd_lvm_lvorigin = bd_lvm_lvorigin_stub;
    _bd_lvm_lvcreate = bd_lvm_lvcreate_stub;
    _bd_lvm_lvremove = bd_lvm_lvremove_stub;
    _bd_lvm_lvrename = bd_lvm_lvrename_stub;
    _bd_lvm_lvresize = bd_lvm_lvresize_stub;
    _bd_lvm_lvactivate = bd_lvm_lvactivate_stub;
    _bd_lvm_lvdeactivate = bd_lvm_lvdeactivate_stub;
    _bd_lvm_lvsnapshotcreate = bd_lvm_lvsnapshotcreate_stub;
    _bd_lvm_lvsnapshotmerge = bd_lvm_lvsnapshotmerge_stub;
    _bd_lvm_lvinfo = bd_lvm_lvinfo_stub;
    _bd_lvm_lvs = bd_lvm_lvs_stub;
    _bd_lvm_thpoolcreate = bd_lvm_thpoolcreate_stub;
    _bd_lvm_thlvcreate = bd_lvm_thlvcreate_stub;
    _bd_lvm_thlvpoolname = bd_lvm_thlvpoolname_stub;
    _bd_lvm_thsnapshotcreate = bd_lvm_thsnapshotcreate_stub;
    _bd_lvm_set_global_config = bd_lvm_set_global_config_stub;
    _bd_lvm_get_global_config = bd_lvm_get_global_config_stub;
    _bd_lvm_cache_get_default_md_size = bd_lvm_cache_get_default_md_size_stub;
    _bd_lvm_cache_get_mode_str = bd_lvm_cache_get_mode_str_stub;
    _bd_lvm_cache_get_mode_from_str = bd_lvm_cache_get_mode_from_str_stub;
    _bd_lvm_cache_create_pool = bd_lvm_cache_create_pool_stub;
    _bd_lvm_cache_attach = bd_lvm_cache_attach_stub;
    _bd_lvm_cache_detach = bd_lvm_cache_detach_stub;
    _bd_lvm_cache_create_cached_lv = bd_lvm_cache_create_cached_lv_stub;
    _bd_lvm_cache_pool_name = bd_lvm_cache_pool_name_stub;
    _bd_lvm_cache_stats = bd_lvm_cache_stats_stub;
    _bd_lvm_data_lv_name = bd_lvm_data_lv_name_stub;
    _bd_lvm_metadata_lv_name = bd_lvm_metadata_lv_name_stub;

    return dlclose(handle) == 0;
}

