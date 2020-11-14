int glob1, glob2;
main() {
	int m_local1, m_local2;

	printf("process id = %d\n", getpid());
	printf("main local : \n\t%p, \n\t%p\n", &m_local1, &m_local2);
	printf("global : \n\t%p, \n\t%p\n", &glob2, &glob1);

	while (1);
}
