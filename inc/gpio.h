/************************************************************************************************
Copyright (c) 2023, Santiago Bualó <santibualo@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/** @file
 ** @brief Driver genérico para el manejo de GPIOs
 **/

/* === Headers files inclusions ================================================================ */
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
#ifndef MAX_GPIO_NUMBER
#define MAX_GPIO_NUMBER 8 //!< Numero máximo de GPIO permitidos para el driver
#endif
/* === Public data type declarations =========================================================== */
typedef struct GPIO_h * GPIO_t; //!< Estructura del GPIO genérico

typedef enum {
    GPIO_OUTPUT_MODE,
    GPIO_INPUT_MODE
} GPIO_output_config_t; //!< Estructura del GPIO de configuracion del modo de operacion
typedef enum {
    GPIO_STATE_OFF,
    GPIO_STATE_ON
} GPIO_state_config_t; //!< Estructura de GPIO para determinar el estado de la salida

/* === Public variable declarations ============================================================
 */

/* === Public function declarations
   ============================================================ */
/**
 * @brief Función que inicializa el GPIO para ser utilizado
 *
 * @param port uint8_t direccion de puerto del GPIO
 * @param pin uint8_t numero del pin asociado al puerto
 * @param output GPIO_output_config_t configuracion inicial del GPIO siendo false para input, true
 * para output
 * @return int Valor de retorno de error, 0 si está todo bien, negativo si hubo error
 */
GPIO_t GPIO_Create(uint8_t port, uint8_t pin, GPIO_output_config_t output);

/**
 * @brief Función para configurar el modo de operación del GPIO
 *
 * @param port GPIO_t Puerto GPIO a configurar
 * @param output GPIO_output_config_t configuracion de modo de operación del GPIO siendo false para
 * input, true para output
 * @return void
 */
void GPIO_Set_Direction(GPIO_t PIN, GPIO_output_config_t output);

/**
 * @brief Función para leer el modo de operacion de un GPIO
 *
 * @param port GPIO_t Puerto GPIO a configurar
 * @return bool modo de operación del GPIO siendo false para input, true para output
 */
bool GPIO_Get_Direction(GPIO_t PIN);

/**
 * @brief Función para configurar el estado de salida del GPIO
 * El GPIO debe estar configurado en modo SALIDA para poder ser utilizado
 *
 * @param port GPIO_t Puerto GPIO a configurar
 * @param state GPIO_state_config_t configuracion del estado de salida/entrada del GPIO siendo 0
 * estado bajo, y 1 estado alto
 * @return bool Valor de retorno de error, true si está todo bien, false si no se pudo realizar el
 * seteo
 */
bool GPIO_Set_State(GPIO_t PIN, GPIO_state_config_t state);

/**
 * @brief Función para obtener el estado de salida/entrada del GPIO
 *
 * @param port GPIO_t Puerto GPIO a configurar
 * @return bool estado de salida/entrada del GPIO siendo false para input, true para output
 */
bool GPIO_Get_State(GPIO_t PIN);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
