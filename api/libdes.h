/*
 *
 * copyright 2019 the wookey project team <wookey@ssi.gouv.fr>
 *   - ryad     benadjila
 *   - arnauld  michelizza
 *   - mathieu  renard
 *   - philippe thierry
 *   - philippe trebuchet
 *
 * this package is free software; you can redistribute it and/or modify
 * it under the terms of the gnu lesser general public license as published
 * the free software foundation; either version 2.1 of the license, or (at
 * ur option) any later version.
 *
 * this package is distributed in the hope that it will be useful, but without any
 * warranty; without even the implied warranty of merchantability or fitness for a
 * particular purpose. see the gnu lesser general public license for more details.
 *
 * you should have received a copy of the gnu lesser general public license along
 * with this package; if not, write to the free software foundation, inc., 51
 * franklin st, fifth floor, boston, ma 02110-1301 usa
 *
 */
#ifndef __LIBDES_H__
#define __LIBDES_H__

#include "libc/types.h"

typedef enum {
        DES_ENCRYPTION = 0,
        DES_DECRYPTION = 1,
} des_direction;

/* DES context */
typedef struct {
    des_direction dir;
    unsigned long long sk[16]; /* encryption/decryption subkeys */
} des_context;

/* Triple DES context */
typedef struct {
    des_direction dir;
    des_context des[3];
} des3_context;

int des_set_key(des_context *ctx, const unsigned char k[8], des_direction dir);

int des_exec(const des_context *ctx, const unsigned char input[8], unsigned char output[8]);

int des3_set_keys(des3_context *ctx, const unsigned char k1[8],  const unsigned char k2[8], const unsigned char k3[8], des_direction dir);

int des3_exec(const des3_context *ctx, const unsigned char input[8], unsigned char output[8]);

#endif /* __LIBDES_H__ */
