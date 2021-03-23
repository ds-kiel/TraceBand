/* main.c - Application main entry point */

/*
 * Copyright (c) 2020 Olaf Landsiedel
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <bluetooth/hci.h>
#include <random/rand32.h>
#include <sys/printk.h>

#include "contacts.h"
#include "covid.h"
#include "covid_types.h"
#include "exposure-notification.h"
#include "gatt_service.h"
#include "io.h"
#include "storage.h"

void main(void) {
    int err = 0;
    printk("Starting Covid Contact Tracer\n");

    // first init everything
    // Use custom randomization as the mbdet_tls context initialization messes with the Zeyhr BLE stack.
    err = en_init(sys_csrand_get);
    if (err) {
        printk("Cyrpto init failed (err %d)\n", err);
        return;
    }

    err = init_contact_storage();
    if (err) {
        printk("init storage failed (err %d)\n", err);
        return;
    }

    init_contacts();
    err = init_io();
    if (err) {
        printk("Button init failed (err %d)\n", err);
        return;
    }

    /* Initialize the Bluetooth Subsystem */
    err = bt_enable(NULL);
    if (err) {
        printk("Bluetooth init failed (err %d)\n", err);
        return;
    }

    printk("Bluetooth initialized\n");

    err = init_gatt();
    if (err) {
        printk("init gatt failed(err %d)\n", err);
        return;
    }

    err = init_covid();
    if (err) {
        printk("init covid failed (err %d)\n", err);
        return;
    }

    do {
        do_covid();
        do_gatt();
    } while (1);
}
