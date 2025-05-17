struct kernel_struct
{
	struct limine_boot_time_response *boot_time;
	struct limine_kernel_address_response *kernel_addr; /* Physical addr and Virtual addr */
	
	void *gdt_addr;
	void *idt_addr;
	void *framebuffer_addr;
};

extern struct kernel_struct kernel;