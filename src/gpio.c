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

#include "gpio.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */
//! estructura con los atributos de un puerto del uC
struct GPIO_h {
    uint8_t port; //! < Puerto del uC a utilizar (ej: GPIO_A)
    uint8_t pin;  //! < Numero de pin asociado al puerto (ej: PIN_13)
    GPIO_state_config_t
        state; //! < Definicion del configuracion de modo del GPIO: input(false) o output(true)
    GPIO_output_config_t output; //! < Estado del GPIO
#ifdef USED_STATIC_MEMORY
    bool used; //! < Flag para determinar si el GPIO esta en uso o no (false = un used)
#endif
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

#ifdef USE_STATIC_MEM
static gpio_t GPIO_Allocate(void) {
    static struct gpio_h instances[MAX_GPIO_INSTANCES] = {
        0}; // !< Instancia del array para los gpio instances

    gpio_t self = NULL;
    for (int index = 0; index < MAX_GPIO_INSTANCES; index++) {
        if (!instances[index].used) {
            self = &instances[index];
            self->used = true;
            break;
        }
    }
    return self;
}
#endif

/* === Public function implementation ========================================================== */

GPIO_t GPIO_Create(uint8_t port, uint8_t pin, GPIO_output_config_t output) {

    GPIO_t self;
#ifdef USED_STATIC_MEMORY
    self = GPIO_Allocate();
#else
    self = malloc(sizeof(struct GPIO_h));
#endif

    if (self) {
        self->port = port;
        self->pin = pin;
        self->output = output;
        self->state = false;
    }
    return self;
}

void GPIO_Set_Direction(GPIO_t self, GPIO_output_config_t output) {
    self->output = output;
}

bool GPIO_Get_Direction(GPIO_t self) {
    return self->output;
}

bool GPIO_Set_State(GPIO_t self, GPIO_state_config_t state) {
    bool correctSet = false;
    if (self->output) {
        self->state = state;
        correctSet = true;
    }
    return correctSet;
}
bool GPIO_Get_State(GPIO_t self) {
    return self->state;
}

/* === End of documentation ==================================================================== */
