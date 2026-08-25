#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Pan", 200, 3};    /* Subtotal: 200 * 3 = 600 */
    Producto p2 = {"Leche", 350, 2};  /* Subtotal: 350 * 2 = 700 */
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    /* Verificamos el total sin descuento ($1300) */
    int total = carrito_total(&c);
    ASSERT_IGUAL(1300, total);
    /* Calculamos el 10% de descuento y verificamos el precio final ($1170) */
    int total_con_descuento = total * 0.90;
    ASSERT_IGUAL(1170, total_con_descuento);
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar y verificar estado]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Galletitas", 150, 1};
    /* 1. Llenar el carrito hasta su capacidad máxima (4 productos) */
    for (int i = 0; i < 4; i++) {
        carrito_agregar(&c, p);
    }
    /* 2. Verificar que el conteo es MAX_ITEMS (4) */
    ASSERT_IGUAL(4, carrito_contar(&c));
    /* 3. Verificar que intentar agregar uno más devuelve 0 (fallo) */
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
    /* 4. Verificar que el conteo sigue siendo MAX_ITEMS (4) y no cambió */
    ASSERT_IGUAL(4, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
