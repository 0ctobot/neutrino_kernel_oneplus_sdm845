/* SPDX-License-Identifier: GPL-2.0
 *
 * Copyright (C) 2018-2019 Sultan Alsawaf <sultan@kerneltoast.com>.
 */
#ifndef _CPU_INPUT_BOOST_H_
#define _CPU_INPUT_BOOST_H_

#ifdef CONFIG_CPU_INPUT_BOOST
extern unsigned long last_input_jiffies;

void cpu_input_boost_kick(void);
void cpu_input_boost_kick_max(unsigned int duration_ms);
void cpu_frame_boost_kick(unsigned int duration_ms);

bool should_kick_frame_boost(void);
#else
static inline void cpu_input_boost_kick(void)
{
}
static inline void cpu_input_boost_kick_max(unsigned int duration_ms)
{
}
static inline void cpu_frame_boost_kick(unsigned int duration_ms)
{
}

static inline bool should_kick_frame_boost(void)
{
	return false;
}
#endif

#endif /* _CPU_INPUT_BOOST_H_ */
