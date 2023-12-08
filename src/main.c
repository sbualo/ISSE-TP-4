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

/** @file
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */

#include "main.h"
#include "gpio.h"

/* === Macros definitions ====================================================================== */
#define GPIO_A    1
#define GPIO_B    2

#define GPIO_PIN3 3
#define GPIO_PIN5 5

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/**
 * @brief Función para setear un delay fijo
 * @return void
 */
void Delay(void){};

int main(void) {

    GPIO_t led_rojo;
    GPIO_t led_verde;

    led_rojo = GPIO_Create(GPIO_A, GPIO_PIN3, GPIO_OUTPUT_MODE);
    led_verde = GPIO_Create(GPIO_B, GPIO_PIN5, GPIO_OUTPUT_MODE);

    while (1) {
        GPIO_Set_State(led_rojo, GPIO_STATE_ON);
        Delay();
        GPIO_Set_State(led_rojo, GPIO_STATE_ON);
    }
    return 0;
}

/* === End of documentation ==================================================================== */
