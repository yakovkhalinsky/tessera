/* SPDX-License-Identifier: GPL-3.0-only */
/* ORACLE's patch layout: the Prophet's panel in its own order. Kept in a header
 * of its own, apart from eng_oracle.c, so the parameter registry (params.c) and
 * ORACLE's pages (oracle_pages.c) can name it without the engine itself: a
 * target without an ORACLE (the o_C port) still reads the FM-1's parameter
 * table. */
enum {                           /* the patch: the Prophet's panel in its own order */
    OR_FREQ_A, OR_FREQ_B, OR_FINE_B, OR_SAW_A, OR_PULSE_A,
    OR_SAW_B, OR_TRI_B, OR_PULSE_B, OR_PW_A, OR_PW_B,
    OR_SYNC, OR_LOW_B, OR_KEY_B, OR_GLIDE, OR_LEVEL_A, OR_LEVEL_B,
    OR_NOISE, OR_CUTOFF, OR_RESONANCE, OR_KEY_FILTER, OR_FILTER_REV,
    OR_LFO_RATE, OR_LFO_INITIAL, OR_LFO_SAW, OR_LFO_TRI, OR_LFO_PULSE,
    OR_WHEEL_MIX, OR_WHEEL_FREQ_A, OR_WHEEL_FREQ_B, OR_WHEEL_PW_A,
    OR_WHEEL_PW_B, OR_WHEEL_FILTER, OR_POLY_ENV, OR_POLY_B,
    OR_POLY_FREQ, OR_POLY_PW, OR_POLY_FILTER, OR_VINTAGE,
    OR_PRESS_FILTER, OR_PRESS_LFO, OR_ENV_FILTER, OR_VEL_FILTER,
    OR_VEL_AMP, OR_ATTACK_FILTER, OR_ATTACK_AMP, OR_DECAY_FILTER,
    OR_DECAY_AMP, OR_SUSTAIN_FILTER, OR_SUSTAIN_AMP, OR_RELEASE_FILTER,
    OR_RELEASE_AMP, OR_RELEASE_ON,
    OR_N                         /* 52 bytes a track */
};
