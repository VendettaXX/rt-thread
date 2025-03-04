/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-10-20     luobeihai    first version
 */

#ifndef __DRV_ETH_H__
#define __DRV_ETH_H__

#include <rtthread.h>
#include <rthw.h>
#include <rtdevice.h>
#include <board.h>

#ifndef LOG_TAG
#define DBG_TAG               "drv"
#else
#define DBG_TAG               LOG_TAG
#endif /* LOG_TAG */

#ifdef DRV_DEBUG
#define DBG_LVL               DBG_LOG
#else
#define DBG_LVL               DBG_INFO
#endif /* DRV_DEBUG */

#include <rtdbg.h>


/* The PHY ID one register */
#define PHY_ID1_REG                 0x02U


#ifdef PHY_USING_LAN8720A
/*  The PHY interrupt source flag register. */
#define PHY_INTERRUPT_FLAG_REG      0x1DU
/*  The PHY interrupt mask register. */
#define PHY_INTERRUPT_MASK_REG      0x1EU
#define PHY_LINK_DOWN_MASK          (1<<4)
#define PHY_AUTO_NEGO_COMPLETE_MASK (1<<6)

/*  The PHY status register. */
#define PHY_Status_REG              0x1FU
#define PHY_10M_MASK                (1<<2)
#define PHY_100M_MASK               (1<<3)
#define PHY_FULL_DUPLEX_MASK        (1<<4)
#define PHY_Status_SPEED_10M(sr)    ((sr) & PHY_10M_MASK)
#define PHY_Status_SPEED_100M(sr)   ((sr) & PHY_100M_MASK)
#define PHY_Status_FULL_DUPLEX(sr)  ((sr) & PHY_FULL_DUPLEX_MASK)

#elif defined(PHY_USING_DM9161CEP)
#define PHY_Status_REG              0x11U
#define PHY_10M_MASK                ((1<<12) || (1<<13))
#define PHY_100M_MASK               ((1<<14) || (1<<15))
#define PHY_FULL_DUPLEX_MASK        ((1<<15) || (1<<13))
#define PHY_Status_SPEED_10M(sr)    ((sr) & PHY_10M_MASK)
#define PHY_Status_SPEED_100M(sr)   ((sr) & PHY_100M_MASK)
#define PHY_Status_FULL_DUPLEX(sr)  ((sr) & PHY_FULL_DUPLEX_MASK)
/*  The PHY interrupt source flag register. */
#define PHY_INTERRUPT_FLAG_REG      0x15U
/*  The PHY interrupt mask register. */
#define PHY_INTERRUPT_MASK_REG      0x15U
#define PHY_LINK_CHANGE_FLAG        (1<<2)
#define PHY_LINK_CHANGE_MASK        (1<<9)
#define PHY_INT_MASK                0

#elif defined(PHY_USING_DP83848C)
#define PHY_Status_REG              0x10U
#define PHY_10M_MASK                (1<<1)
#define PHY_FULL_DUPLEX_MASK        (1<<2)
#define PHY_Status_SPEED_10M(sr)    ((sr) & PHY_10M_MASK)
#define PHY_Status_SPEED_100M(sr)   (!PHY_Status_SPEED_10M(sr))
#define PHY_Status_FULL_DUPLEX(sr)  ((sr) & PHY_FULL_DUPLEX_MASK)
/*  The PHY interrupt source flag register. */
#define PHY_INTERRUPT_FLAG_REG      0x12U
#define PHY_LINK_CHANGE_FLAG        (1<<13)
/*  The PHY interrupt control register. */
#define PHY_INTERRUPT_CTRL_REG      0x11U
#define PHY_INTERRUPT_EN            ((1<<0)|(1<<1))
/*  The PHY interrupt mask register. */
#define PHY_INTERRUPT_MASK_REG      0x12U
#define PHY_INT_MASK                (1<<5)
#endif

#ifdef PHY_USING_LAN8742A
/*  The PHY interrupt source flag register. */
#define PHY_INTERRUPT_FLAG_REG      0x1DU
/*  The PHY interrupt mask register. */
#define PHY_INTERRUPT_MASK_REG      0x1EU
#define PHY_LINK_DOWN_MASK          (1<<4)
#define PHY_AUTO_NEGO_COMPLETE_MASK (1<<6)

/*  The PHY status register. */
#define PHY_Status_REG              0x1FU
#define PHY_10M_MASK                (1<<2)
#define PHY_100M_MASK               (1<<3)
#define PHY_FULL_DUPLEX_MASK        (1<<4)
#define PHY_Status_SPEED_10M(sr)    ((sr) & PHY_10M_MASK)
#define PHY_Status_SPEED_100M(sr)   ((sr) & PHY_100M_MASK)
#define PHY_Status_FULL_DUPLEX(sr)  ((sr) & PHY_FULL_DUPLEX_MASK)
#endif /* PHY_USING_LAN8742A */

#endif /* __DRV_ETH_H__ */
