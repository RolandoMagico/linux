// SPDX-License-Identifier: GPL-2.0-only
/*
 * ONIE tlv NVMEM cells provider
 *
 * Copyright (C) 2022 Open Compute Group ONIE
 * Author: Miquel Raynal <miquel.raynal@bootlin.com>
 * Based on the nvmem driver written by: Vadym Kochan <vadym.kochan@plvision.eu>
 * Inspired by the first layout written by: Rafał Miłecki <rafal@milecki.pl>
 */

#include <kunit/test.h>
#include <linux/nvmem-consumer.h>

/* Dummy TLV: type=0x21, len=5, "TEST\0" */
static u8 sample_tlv[] = {
    0x21, 0x05, 'T','E','S','T','\0'
};

static void dlink_tlv_basic_parse_test(struct kunit *test)
{
    int ret;

    ret = dlink_odm_tlv_parse(NULL,
                              sample_tlv,
                              sizeof(sample_tlv),
                              NULL);

    KUNIT_EXPECT_EQ(test, ret, 0);
}