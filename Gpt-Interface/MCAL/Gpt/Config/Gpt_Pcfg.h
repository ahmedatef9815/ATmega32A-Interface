#ifndef GPT_PCFG_H_
#define GPT_PCFG_H_

#define GPT_CHANNELS_NUMBER                             (3U)

#define TIMER0_FORCE_OUT_CMP_BIT                        (7U)
#define TIMER0_OUT_CMP_MATCH_INTERRUPT_ENABLE_BIT       (1U)
#define TIMER0_OVERFLOW_INTERRUPT_ENABLE_BIT            (0U)
#define TIMER0_OUT_CMP_FLAG_BIT                         (1U)
#define TIMER0_OVERFLOW_FLAG_BIT                        (0U)


#define TIMER1_OVERFLOW_FLAG_BIT                        (2U)
#define TIMER1_FORCE_OUT_CMP_FOR_CMP_UNIT_A_BIT         (3U)
#define TIMER1_FORCE_OUT_CMP_FOR_CMP_UNIT_B_BIT         (2U)
#define TIMER1_OUT_CMP_A_MATCH_INTERRUPT_ENABLE_BIT     (4U)
#define TIMER1_OUT_CMP_B_MATCH_INTERRUPT_ENABLE_BIT     (3U)
#define TIMER1_OVERFLOW_INTERRUPT_ENABLE_BIT            (2U)
#define TIMER1_OUT_CMP_A_MATCH_FLAG_BIT                 (4U)
#define TIMER1_OUT_CMP_B_MATCH_FLAG_BIT                 (3U)


#define TIMER2_FORCE_OUT_CMP_BIT                        (7U)
#define TIMER2_ASYNCHRONOUS_BIT                         (3U)
#define TIMER2_UPDATE_BUSY_BIT                          (2U)
#define TIMER2_OUT_CMP_REG_UPDATE_BUSY_BIT              (1U)
#define TIMER2_CTRL_REG_UPDATE_BUSY_BIT                 (0U)
#define TIMER2_OUT_CMP_MATCH_INTERRUPT_ENABLE_BIT       (7U)
#define TIMER2_OVERFLOW_INTERRUPT_ENABLE_BIT            (6U)
#define TIMER2_OUT_CMP_FLAG_BIT                         (7U)
#define TIMER2_OVERFLOW_FLAG_BIT                        (6U)
  

#endif /* GPT_PCFG_H_ */