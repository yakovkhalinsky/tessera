/* SPDX-License-Identifier: GPL-3.0-only
 * Copyright (C) 2026 Leo Kuroshita (@kurogedelic), Hügelton Instruments
 * Modifications Copyright (C) 2026 Kerem Kilic (Ellic Studio) */
/* FM6's patch layout and its function settings: the indices into the
 * 155-byte voice patch and the names of the DX7's function modes. Kept in a
 * header of their own, apart from fm6_core.c, so the parameter registry
 * (params.c) can name the FM6's pages without the engine itself: a target
 * without an FM6 (the o_C port) still reads the FM-1's parameter table. */

#include "x0x/fastmath.h"

/* the 155-byte patch: 6 x 21 operator bytes (the sixth operator first), then the voice */
enum {
    FP_R1 = 0, FP_L1 = 4, FP_BP = 8, FP_LD, FP_RD, FP_LC, FP_RC, FP_RS, FP_AMS, FP_KVS, FP_OL, FP_MODE, FP_FC, FP_FF,
    FP_DET, FP_OP = 21,
    FP_PR1 = 126, FP_PL1 = 130, FP_ALG = 134, FP_FB, FP_OKS, FP_LFS, FP_LFD, FP_LPMD, FP_LAMD, FP_LKS, FP_LFW,
    FP_LPMS, FP_TRNSP, FP_NAME, FP_SIZE = 155
};

/* the FM6 function settings (a DX7's function mode; each track its own, as each Dexed instance has, saved with the
 * project and the template; project.c):
 * pitch bend range up / down and step (0 = smooth), portamento (PEDAL: while CC 65 is down, ON) and its time
 * (CC 5 sets it) and glissando, then wheel, foot, breath and aftertouch: range and target (bit 0 pitch, 1
 * amplitude, 2 EG bias), Dexed's velocity scaling to the DX7's range, and ENGINE */
enum { FN_PBUP, FN_PBDN, FN_PBSTEP, FN_PMODE, FN_PTIME, FN_GLISS, FN_MWR, FN_MWA, FN_FCR, FN_FCA, FN_BCR, FN_BCA,
       FN_ATR, FN_ATA, FN_VNORM, FN_ENGINE, FM6_NFN };
enum { FM6_MODERN, FM6_MARK1, FM6_OPL };

/* the FM6's 2^x, in the Q16 the DX7's frequency text uses */
static inline __attribute__((always_inline)) uint32_t fm6_pow2(int32_t x)
{
    return (uint32_t)fm_minf(fm_exp2f((float)x * (1.0f / 65536.0f)) * 65536.0f, 4294967040.0f);
}
