/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_LIST_SORT_H
#define _LINUX_LIST_SORT_H

struct list_head;

typedef int __attribute__((nonnull(2,3))) (*list_cmp_func_t)(void *,
		const struct list_head *, const struct list_head *);

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((nonnull(2,3)))
void list_sort(void *priv, struct list_head *head, list_cmp_func_t cmp);

#ifdef __cplusplus
}
#endif

#endif
