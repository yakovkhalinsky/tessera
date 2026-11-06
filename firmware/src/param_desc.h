/* SPDX-License-Identifier: GPL-3.0-only
 * Copyright (C) 2026 Leo Kuroshita (@kurogedelic), Hügelton Instruments */
#pragma once
/* A parameter's descriptor: its label, its format, its range, its default and,
 * for an enum, the names. Kept in a header of its own, apart from core.h, so a
 * target with its own screen can read the parameters without the engine's
 * structures: the o_C port draws its list from these.
 */
typedef struct {
    const char *label;
    uint8_t fmt;
    int16_t min, max, def;
    const char *const *names;   /* F_ENUM */
    const char *unit;           /* F_INT / F_ENUM optional unit */
} param_desc_t;
