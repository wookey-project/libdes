.. _lib_des:

the (T)DES library
==================

.. contents::

the libdes project aim to implement the DES (Data Encryption Standard) and TDES
(Triple Data Encryption Standard) algorithms.

By now, this algorithms are only fully software based (i.e. they don't depend on
any hardware cryptographic accelerator).

Overview
--------

Principles
""""""""""

TODO: basic (T)DES principles and why here

Limitations
"""""""""""

TODO: the library limitations

The libdes API
--------------

The libdes API does not require any initialization phase.

DES data (de/en)cryption
""""""""""""""""""""""""

Data encryption and decryption using DES algorithm is done using the following API ::

   #include "libdes.h"

   int des_set_key(      des_context   *ctx,
                   const unsigned char  k[8],
                         des_direction  dir);
   int des_exec(const des_context    *ctx,
                const unsigned char   input[8],
                      unsigned char   output[8]);

Encrypting or decrypting data is done in two times:

   * setting the DES key and the algorithm direction, using ``des_set_key()``
   * Encrypting or decrypting successive data chunk of 8 bytes, using ``des_exec()``

The ``des_context`` structure contains the following fields:

   * **dir**: the algorithm direction, DES_ENCRYPTION or DES_DECRYPTION
   * **sk**: the DES subkeys

These two fields are set by the ``des_set_key()`` function, based on the two other arguments:

   * **k**: the DES key to use
   * **dir**: the DES algorithm direction to use

the DES context can be keeped by the caller task in order to use it during each successive
DES execution through ``des_exec()``.

.. hint::
   It is possible to use multiple DES contexts for multiple cryptographic actions in the same time


.. info::
   When executing des_exec(), the input content must be padded to 8 bytes


TDES data (de/en)cryption
"""""""""""""""""""""""""

Data encryption and decryption using Triple-DES algorithm is done using the following API ::

   #include "libdes.h"

   int des3_set_key(      des_context   *ctx,
                    const unsigned char  k1[8],
                    const unsigned char  k2[8],
                    const unsigned char  k3[8],
                          des_direction  dir);
   int des3_exec(const des_context    *ctx,
                 const unsigned char   input[8],
                      unsigned char   output[8]);

Encrypting or decrypting data is done in two times:

   * setting the three DES keys and the algorithm direction, using ``des3_set_key()``
   * Encrypting or decrypting successive data chunk of 8 bytes, using ``des3_exec()``

these two functions can be used in the same way the DES API is.

