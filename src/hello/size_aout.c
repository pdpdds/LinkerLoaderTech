int
show(count, name)
	int count;
	char *name;
{
	static int first = 1;
	struct exec head;
	u_long total;
	int fd;

	if ((fd = open(name, O_RDONLY, 0)) < 0) {
		warn("%s", name);
		return (1);
	}
	if (read(fd, &head, sizeof(head)) != sizeof(head) || N_BADMAG(head)) {
		(void)close(fd);
		warnx("%s: not in a.out format", name);
		return (1);
	}
	(void)close(fd);

	if (first) {
		first = 0;
		(void)printf("text\tdata\tbss\tdec\thex\n");
	}
	total = head.a_text + head.a_data + head.a_bss;
	(void)printf("%lu\t%lu\t%lu\t%lu\t%lx", (u_long)head.a_text,
	    (u_long)head.a_data, (u_long)head.a_bss, total, total);
	if (count > 1)
		(void)printf("\t%s", name);
	(void)printf("\n");
	return (0);
}
