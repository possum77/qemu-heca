#ifndef HW_MCF_H
#define HW_MCF_H
/* Motorola ColdFire device prototypes.  */

struct MemoryRegion;

/* mcf_uart.c */
uint64_t mcf_uart_read(void *opaque, hwaddr addr,
                       unsigned size);
void mcf_uart_write(void *opaque, hwaddr addr,
                    uint64_t val, unsigned size);
void *mcf_uart_init(qemu_irq irq, CharDriverState *chr);
void mcf_uart_mm_init(struct MemoryRegion *sysmem,
                      hwaddr base,
                      qemu_irq irq, CharDriverState *chr);

/* mcf_intc.c */
qemu_irq *mcf_intc_init(struct MemoryRegion *sysmem,
                        hwaddr base,
                        CPUM68KState *env);

/* mcf_fec.c */
void mcf_fec_init(struct MemoryRegion *sysmem, NICInfo *nd,
                  hwaddr base, qemu_irq *irq);

/* mcf5206.c */
qemu_irq *mcf5206_init(struct MemoryRegion *sysmem,
                       uint32_t base, CPUM68KState *env);

#endif
