#ifndef _GBA_FUNCS_H_
#define _GBA_FUNCS_H_

#include "gba_def.h"
#include "gba_mmap.h"
#include "gba_types.h"
#include "gba_util_macros.h"
#ifdef __cplusplus
#include <cstddef>
extern "C" {
#else
#include <stddef.h>
#include <stdbool.h>
#endif


void vsync(void);
void IntrWait(u32 discard, u32 flags);


IWRAM_CODE void ISR_MAIN_HANDLER(void);

IWRAM_CODE void fast_memset32(void *dst, u32 val, size_t word_ct);
IWRAM_CODE void fast_memcpy32(void *dst, const void *src, size_t word_ct);
#define MODE3_CLEAR_SCREEN() fast_memset32(VRAM_BUF, 0, SCREEN_WIDTH*SCREEN_HEIGHT/2)

bool SRAM_Read(void *dest, size_t len, size_t ofs);
bool SRAM_Write(const void *data, size_t len, size_t ofs);


void mode3_draw_rect(const BMP_Rect_t *rect);

void oam_cpy(Obj_Attrs_t *dst, const Obj_Attrs_t *src, u32 ct);
void oam_init_ofs(Obj_Attrs_t *objs, u32 ct, u32 ofs);
void oam_init(Obj_Attrs_t *objs, u32 ct);
void obj_affine_cpy(Obj_Affine_t *dst, const Obj_Affine_t *src, u32 ct);


void IRQ_Init(IRQ_Callback_t isr_handler);
void IRQ_Enable(enum IRQ_Idx interrupt_type);
void IRQ_Disable(enum IRQ_Idx interrupt_type);
IRQ_Callback_t IRQ_Add(enum IRQ_Idx interrupt_type, IRQ_Callback_t isr, u32 priority);
IRQ_Callback_t IRQ_Remove(enum IRQ_Idx interrupt_type);

void SIO_Set_Multi(u16 baud);


static inline void mode3_clear_screen(void) {
  fast_memset32(VRAM_BUF, 0, (SCREEN_WIDTH*SCREEN_HEIGHT)>>1);
}



#ifdef __cplusplus
}
#endif

#endif  /* _GBA_FUNCS_H_ */
