/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _BCACHEFS_SB_ERRORS_TYPES_H
#define _BCACHEFS_SB_ERRORS_TYPES_H

#include "darray.h"

#define BCH_SB_ERRS()							\
	x(clean_but_journal_not_empty,				0)	\
	x(dirty_but_no_journal_entries,				1)	\
	x(dirty_but_no_journal_entries_post_drop_nonflushes,	2)	\
	x(sb_clean_journal_seq_mismatch,			3)	\
	x(sb_clean_btree_root_mismatch,				4)	\
	x(sb_clean_missing,					5)	\
	x(jset_unsupported_version,				6)	\
	x(jset_unknown_csum,					7)	\
	x(jset_last_seq_newer_than_seq,				8)	\
	x(jset_past_bucket_end,					9)	\
	x(jset_seq_blacklisted,					10)	\
	x(journal_entries_missing,				11)	\
	x(journal_entry_replicas_not_marked,			12)	\
	x(journal_entry_past_jset_end,				13)	\
	x(journal_entry_replicas_data_mismatch,			14)	\
	x(journal_entry_bkey_u64s_0,				15)	\
	x(journal_entry_bkey_past_end,				16)	\
	x(journal_entry_bkey_bad_format,			17)	\
	x(journal_entry_bkey_invalid,				18)	\
	x(journal_entry_btree_root_bad_size,			19)	\
	x(journal_entry_blacklist_bad_size,			20)	\
	x(journal_entry_blacklist_v2_bad_size,			21)	\
	x(journal_entry_blacklist_v2_start_past_end,		22)	\
	x(journal_entry_usage_bad_size,				23)	\
	x(journal_entry_data_usage_bad_size,			24)	\
	x(journal_entry_clock_bad_size,				25)	\
	x(journal_entry_clock_bad_rw,				26)	\
	x(journal_entry_dev_usage_bad_size,			27)	\
	x(journal_entry_dev_usage_bad_dev,			28)	\
	x(journal_entry_dev_usage_bad_pad,			29)	\
	x(btree_node_unreadable,				30)	\
	x(btree_node_fault_injected,				31)	\
	x(btree_node_bad_magic,					32)	\
	x(btree_node_bad_seq,					33)	\
	x(btree_node_unsupported_version,			34)	\
	x(btree_node_bset_older_than_sb_min,			35)	\
	x(btree_node_bset_newer_than_sb,			36)	\
	x(btree_node_data_missing,				37)	\
	x(btree_node_bset_after_end,				38)	\
	x(btree_node_replicas_sectors_written_mismatch,		39)	\
	x(btree_node_replicas_data_mismatch,			40)	\
	x(bset_unknown_csum,					41)	\
	x(bset_bad_csum,					42)	\
	x(bset_past_end_of_btree_node,				43)	\
	x(bset_wrong_sector_offset,				44)	\
	x(bset_empty,						45)	\
	x(bset_bad_seq,						46)	\
	x(bset_blacklisted_journal_seq,				47)	\
	x(first_bset_blacklisted_journal_seq,			48)	\
	x(btree_node_bad_btree,					49)	\
	x(btree_node_bad_level,					50)	\
	x(btree_node_bad_min_key,				51)	\
	x(btree_node_bad_max_key,				52)	\
	x(btree_node_bad_format,				53)	\
	x(btree_node_bkey_past_bset_end,			54)	\
	x(btree_node_bkey_bad_format,				55)	\
	x(btree_node_bad_bkey,					56)	\
	x(btree_node_bkey_out_of_order,				57)	\
	x(btree_root_bkey_invalid,				58)	\
	x(btree_root_read_error,				59)	\
	x(btree_root_bad_min_key,				60)	\
	x(btree_root_bad_max_key,				61)	\
	x(btree_node_read_error,				62)	\
	x(btree_node_topology_bad_min_key,			63)	\
	x(btree_node_topology_bad_max_key,			64)	\
	x(btree_node_topology_overwritten_by_prev_node,		65)	\
	x(btree_node_topology_overwritten_by_next_node,		66)	\
	x(btree_node_topology_interior_node_empty,		67)	\
	x(fs_usage_hidden_wrong,				68)	\
	x(fs_usage_btree_wrong,					69)	\
	x(fs_usage_data_wrong,					70)	\
	x(fs_usage_cached_wrong,				71)	\
	x(fs_usage_reserved_wrong,				72)	\
	x(fs_usage_persistent_reserved_wrong,			73)	\
	x(fs_usage_nr_inodes_wrong,				74)	\
	x(fs_usage_replicas_wrong,				75)	\
	x(dev_usage_buckets_wrong,				76)	\
	x(dev_usage_sectors_wrong,				77)	\
	x(dev_usage_fragmented_wrong,				78)	\
	x(dev_usage_buckets_ec_wrong,				79)	\
	x(bkey_version_in_future,				80)	\
	x(bkey_u64s_too_small,					81)	\
	x(bkey_invalid_type_for_btree,				82)	\
	x(bkey_extent_size_zero,				83)	\
	x(bkey_extent_size_greater_than_offset,			84)	\
	x(bkey_size_nonzero,					85)	\
	x(bkey_snapshot_nonzero,				86)	\
	x(bkey_snapshot_zero,					87)	\
	x(bkey_at_pos_max,					88)	\
	x(bkey_before_start_of_btree_node,			89)	\
	x(bkey_after_end_of_btree_node,				90)	\
	x(bkey_val_size_nonzero,				91)	\
	x(bkey_val_size_too_small,				92)	\
	x(alloc_v1_val_size_bad,				93)	\
	x(alloc_v2_unpack_error,				94)	\
	x(alloc_v3_unpack_error,				95)	\
	x(alloc_v4_val_size_bad,				96)	\
	x(alloc_v4_backpointers_start_bad,			97)	\
	x(alloc_key_data_type_bad,				98)	\
	x(alloc_key_empty_but_have_data,			99)	\
	x(alloc_key_dirty_sectors_0,				100)	\
	x(alloc_key_data_type_inconsistency,			101)	\
	x(alloc_key_to_missing_dev_bucket,			102)	\
	x(alloc_key_cached_inconsistency,			103)	\
	x(alloc_key_cached_but_read_time_zero,			104)	\
	x(alloc_key_to_missing_lru_entry,			105)	\
	x(alloc_key_data_type_wrong,				106)	\
	x(alloc_key_gen_wrong,					107)	\
	x(alloc_key_dirty_sectors_wrong,			108)	\
	x(alloc_key_cached_sectors_wrong,			109)	\
	x(alloc_key_stripe_wrong,				110)	\
	x(alloc_key_stripe_redundancy_wrong,			111)	\
	x(bucket_sector_count_overflow,				112)	\
	x(bucket_metadata_type_mismatch,			113)	\
	x(need_discard_key_wrong,				114)	\
	x(freespace_key_wrong,					115)	\
	x(freespace_hole_missing,				116)	\
	x(bucket_gens_val_size_bad,				117)	\
	x(bucket_gens_key_wrong,				118)	\
	x(bucket_gens_hole_wrong,				119)	\
	x(bucket_gens_to_invalid_dev,				120)	\
	x(bucket_gens_to_invalid_buckets,			121)	\
	x(bucket_gens_nonzero_for_invalid_buckets,		122)	\
	x(need_discard_freespace_key_to_invalid_dev_bucket,	123)	\
	x(need_discard_freespace_key_bad,			124)	\
	x(backpointer_pos_wrong,				125)	\
	x(backpointer_to_missing_device,			126)	\
	x(backpointer_to_missing_alloc,				127)	\
	x(backpointer_to_missing_ptr,				128)	\
	x(lru_entry_at_time_0,					129)	\
	x(lru_entry_to_invalid_bucket,				130)	\
	x(lru_entry_bad,					131)	\
	x(btree_ptr_val_too_big,				132)	\
	x(btree_ptr_v2_val_too_big,				133)	\
	x(btree_ptr_has_non_ptr,				134)	\
	x(extent_ptrs_invalid_entry,				135)	\
	x(extent_ptrs_no_ptrs,					136)	\
	x(extent_ptrs_too_many_ptrs,				137)	\
	x(extent_ptrs_redundant_crc,				138)	\
	x(extent_ptrs_redundant_stripe,				139)	\
	x(extent_ptrs_unwritten,				140)	\
	x(extent_ptrs_written_and_unwritten,			141)	\
	x(ptr_to_invalid_device,				142)	\
	x(ptr_to_duplicate_device,				143)	\
	x(ptr_after_last_bucket,				144)	\
	x(ptr_before_first_bucket,				145)	\
	x(ptr_spans_multiple_buckets,				146)	\
	x(ptr_to_missing_backpointer,				147)	\
	x(ptr_to_missing_alloc_key,				148)	\
	x(ptr_to_missing_replicas_entry,			149)	\
	x(ptr_to_missing_stripe,				150)	\
	x(ptr_to_incorrect_stripe,				151)	\
	x(ptr_gen_newer_than_bucket_gen,			152)	\
	x(ptr_too_stale,					153)	\
	x(stale_dirty_ptr,					154)	\
	x(ptr_bucket_data_type_mismatch,			155)	\
	x(ptr_cached_and_erasure_coded,				156)	\
	x(ptr_crc_uncompressed_size_too_small,			157)	\
	x(ptr_crc_csum_type_unknown,				158)	\
	x(ptr_crc_compression_type_unknown,			159)	\
	x(ptr_crc_redundant,					160)	\
	x(ptr_crc_uncompressed_size_too_big,			161)	\
	x(ptr_crc_nonce_mismatch,				162)	\
	x(ptr_stripe_redundant,					163)	\
	x(reservation_key_nr_replicas_invalid,			164)	\
	x(reflink_v_refcount_wrong,				165)	\
	x(reflink_p_to_missing_reflink_v,			166)	\
	x(stripe_pos_bad,					167)	\
	x(stripe_val_size_bad,					168)	\
	x(stripe_sector_count_wrong,				169)	\
	x(snapshot_tree_pos_bad,				170)	\
	x(snapshot_tree_to_missing_snapshot,			171)	\
	x(snapshot_tree_to_missing_subvol,			172)	\
	x(snapshot_tree_to_wrong_subvol,			173)	\
	x(snapshot_tree_to_snapshot_subvol,			174)	\
	x(snapshot_pos_bad,					175)	\
	x(snapshot_parent_bad,					176)	\
	x(snapshot_children_not_normalized,			177)	\
	x(snapshot_child_duplicate,				178)	\
	x(snapshot_child_bad,					179)	\
	x(snapshot_skiplist_not_normalized,			180)	\
	x(snapshot_skiplist_bad,				181)	\
	x(snapshot_should_not_have_subvol,			182)	\
	x(snapshot_to_bad_snapshot_tree,			183)	\
	x(snapshot_bad_depth,					184)	\
	x(snapshot_bad_skiplist,				185)	\
	x(subvol_pos_bad,					186)	\
	x(subvol_not_master_and_not_snapshot,			187)	\
	x(subvol_to_missing_root,				188)	\
	x(subvol_root_wrong_bi_subvol,				189)	\
	x(bkey_in_missing_snapshot,				190)	\
	x(inode_pos_inode_nonzero,				191)	\
	x(inode_pos_blockdev_range,				192)	\
	x(inode_unpack_error,					193)	\
	x(inode_str_hash_invalid,				194)	\
	x(inode_v3_fields_start_bad,				195)	\
	x(inode_snapshot_mismatch,				196)	\
	x(inode_unlinked_but_clean,				197)	\
	x(inode_unlinked_but_nlink_nonzero,			198)	\
	x(inode_checksum_type_invalid,				199)	\
	x(inode_compression_type_invalid,			200)	\
	x(inode_subvol_root_but_not_dir,			201)	\
	x(inode_i_size_dirty_but_clean,				202)	\
	x(inode_i_sectors_dirty_but_clean,			203)	\
	x(inode_i_sectors_wrong,				204)	\
	x(inode_dir_wrong_nlink,				205)	\
	x(inode_dir_multiple_links,				206)	\
	x(inode_multiple_links_but_nlink_0,			207)	\
	x(inode_wrong_backpointer,				208)	\
	x(inode_wrong_nlink,					209)	\
	x(inode_unreachable,					210)	\
	x(deleted_inode_but_clean,				211)	\
	x(deleted_inode_missing,				212)	\
	x(deleted_inode_is_dir,					213)	\
	x(deleted_inode_not_unlinked,				214)	\
	x(extent_overlapping,					215)	\
	x(extent_in_missing_inode,				216)	\
	x(extent_in_non_reg_inode,				217)	\
	x(extent_past_end_of_inode,				218)	\
	x(dirent_empty_name,					219)	\
	x(dirent_val_too_big,					220)	\
	x(dirent_name_too_long,					221)	\
	x(dirent_name_embedded_nul,				222)	\
	x(dirent_name_dot_or_dotdot,				223)	\
	x(dirent_name_has_slash,				224)	\
	x(dirent_d_type_wrong,					225)	\
	x(dirent_d_parent_subvol_wrong,				226)	\
	x(dirent_in_missing_dir_inode,				227)	\
	x(dirent_in_non_dir_inode,				228)	\
	x(dirent_to_missing_inode,				229)	\
	x(dirent_to_missing_subvol,				230)	\
	x(dirent_to_itself,					231)	\
	x(quota_type_invalid,					232)	\
	x(xattr_val_size_too_small,				233)	\
	x(xattr_val_size_too_big,				234)	\
	x(xattr_invalid_type,					235)	\
	x(xattr_name_invalid_chars,				236)	\
	x(xattr_in_missing_inode,				237)	\
	x(root_subvol_missing,					238)	\
	x(root_dir_missing,					239)	\
	x(root_inode_not_dir,					240)	\
	x(dir_loop,						241)	\
	x(hash_table_key_duplicate,				242)	\
	x(hash_table_key_wrong_offset,				243)	\
	x(unlinked_inode_not_on_deleted_list,			244)

enum bch_sb_error_id {
#define x(t, n) BCH_FSCK_ERR_##t = n,
	BCH_SB_ERRS()
#undef x
	BCH_SB_ERR_MAX
};

struct bch_sb_error_entry_cpu {
	u64			id:16,
				nr:48;
	u64			last_error_time;
};

typedef DARRAY(struct bch_sb_error_entry_cpu) bch_sb_errors_cpu;

#endif /* _BCACHEFS_SB_ERRORS_TYPES_H */

