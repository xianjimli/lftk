﻿/**
 * File:   mem.h
 * Author: Li XianJing <xianjimli@hotmail.com>
 * Brief:  memory manager functions.
 *
 * Copyright (c) 2018 - 2018  Li XianJing <xianjimli@hotmail.com>
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-01-13 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef LFTK_MEM_MANAGER_H
#define LFTK_MEM_MANAGER_H

#include "base/types_def.h"

BEGIN_C_DECLS

typedef struct _mem_stat_t {
  uint32_t used;
  uint32_t free;
  uint32_t total;
  uint32_t free_block_nr;
  uint32_t used_block_nr;
} mem_stat_t;

ret_t mem_init(void* buffer, uint32_t length);

mem_stat_t mem_stat(void);

void mem_info_dump(void);

#ifdef HAS_STD_MALLOC
#define MEM_ALLOC(size) malloc(size)
#define MEM_ZALLOC(type) (type*)calloc(1, sizeof(type))
#define MEM_ZALLOCN(type, n) (type*)calloc(n, sizeof(type))
#define MEM_REALLOC(type, p, n) (type*)realloc(p, (n) * sizeof(type))
#define MEM_FREE(p) free(p)
#else
void* lftk_calloc(uint32_t nmemb, uint32_t size);
void* lftk_realloc(void* ptr, uint32_t size);
void lftk_free(void* ptr);
void* lftk_alloc(uint32_t size);

#define MEM_ALLOC(size) lftk_alloc(size)
#define MEM_ZALLOC(type) (type*)lftk_calloc(1, sizeof(type))
#define MEM_ZALLOCN(type, n) (type*)lftk_calloc(n, sizeof(type))
#define MEM_REALLOC(type, p, n) (type*)lftk_realloc(p, (n) * sizeof(type))
#define MEM_FREE(p) lftk_free(p)
#endif

END_C_DECLS
#endif /*LFTK_MEM_MANAGER_H*/
