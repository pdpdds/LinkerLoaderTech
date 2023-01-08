2010.08.30 사카이 히로아키

본 파일은 서적
「링커,로더 실전 개발 테크닉」(사카이 히로아키，2010/08，CQ출판사)
의 부록입니다.

■ column

추가 컬럼입니다．마감 날짜 문제로 본문에는 게재되지 않은 내용입니다.   
인쇄해서 지정된 페이지에 끼워 두면 좋을것입니다.

특히 아래 내용은 특별히 설명된 자료가 없기 때문에 한 번 읽어 보는 것이 좋을 것입니다

column-sec6-p152.txt
「MEMORY 커맨드에 따른 어드레스 할당 제어」

column-sec10-p249.txt
「글로벌 포인터의 사용」

■ src

본문에서 소개하고 있는 텍스트(주로 프로그램의 소스코드나 출력결과 등)와  
기타 여러가지입니다.

본 파일의 사용에 대해서는 책임을 지지 않습니다. 개인의 책임하에 사용해 주세요.   
파일의 제작자・출판사는 본 소스코드를 이용해서 발생하는 어떠한 책임도 지지 않습니다.   

잏부 소스코드는 FreeBSD/NetBSD/GNU+Linux 등에서 발췌했습니다. 
이런 소스코드의 저작권은 해당 프로젝트에 있습니다. 해당 프로젝트에 대해서는 서적의 본문을   
참조해 주세요. 특별히 설명이 없는 내용은 FreeBSD 또는 FreeBSD에 첨부되어 배포하는   
GNU 툴의 소스코드가 원 출처입니다.

그 이외의 소스 코드는 서적 집필자인 사카이가 작성한 것입니다.   
개인의 책임 하에 자유롭게 이용해도 괜찮습니다.  

일부 소스 코드는 도서에 소개되지 않은 실험용 코드를 포함합니다.   
자유롭게 이용해 주세요.

다음은 소스 코드 목록입니다.
목록 번호는 책의 본문에서 나온 번호입니다
그림의 경우에는 일부만 책에 게재되어 있습니다만, 출력 결과 등의 많은 그림이   
src 디렉토리 아래에 있으므로 필요하다면 찾아보는 것이 좋습니다.   

--------------------------------------------------------------------------------
리스트 번호	내용						소스코드
--------------------------------------------------------------------------------
```
리스트1.1	hello.c						src/hello/hello.c
리스트1.2	gcc -v 의 결과					src/hello/gcc-v.out
리스트1.3	size hello 의 결과				src/hello/size.out
리스트1.4	objdump -h hello 의 결과				src/hello/objdump.out
리스트1.5	/usr/src/usr.bin/size/size.c 에서 발췌		src/hello/size_aout.c
리스트1.6	struct exec 의 정의(imgact_aout.h 에서 발췌)	src/hello/imgact_aout.h
리스트1.7	hello 의 선두부분의 선두부분 16진수 덤프			src/hello/hello_dump.txt
리스트1.8	/usr/src/contrib/binutils/binutils/size.c 에서 발췌
								src/hello/size_elf.c
리스트1.9	objdump -p hello 의 결과				src/hello/objdump-p.out
리스트1.10	다양한 변수의 정의(values_sub.c)			src/values/values_sub.c
리스트1.11	다양한 변수의 정의(values.c)			src/values/values.c
리스트1.12	nm values_sub.o 의 결과				src/values/values_sub_nm.out
리스트1.13	nm values 의 결과				src/values/values_nm.out
리스트1.14	objdump -h values 의 결과			src/values/objdump.out
리스트1.15	values 의 실행결과				src/values/values.out
리스트1.16	strip values 의 실행결과				src/values/strip.out
리스트1.17	링커스크립트의 모형				---
리스트1.18	엔트리 포인트에 대해(info ld 에서 발췌)	---
리스트1.19	ENTRY()의 지정(elf_i386.x 에서 발췌)		---
--------------------------------------------------------------------------------
리스트2.1	ELF 파일 해석용 샘플(elfsamp.c)		src/elfsamp/elfsamp.c
리스트2.2	ELF 파일 해석용 샘플(main.c)		src/elfsamp/main.c
리스트2.3	ELF32 헤더(elf32.h)				---
리스트2.4	readelf -h elfsamp.o 의 결과			src/elfsamp/readelf-o-h.out
리스트2.5	brandelf.c 에서 발췌			---
리스트2.6	ELF32용 섹션 헤더(elf32.h)		---
리스트2.7	readelf -S elfsamp.o의 결과			src/elfsamp/readelf-o-S.out
리스트2.8	readelf -x 8 elfsamp.o의 결과			src/elfsamp/readelf-o-x.out
리스트2.9	섹션 이름 목록 표시의 예(readsec.c)		src/elfsamp/readsec.c
리스트2.10	ELF32용 프로그램 헤더(elf32.h)		---
리스트2.11	readelf -l elfsamp 의 결과			src/elfsamp/readelf-l.out
리스트2.12	자신의 ELF 헤더를 읽어들이는 예(elfread.c)		src/elfread/elfread.c
리스트2.13 심볼 테이블용 구조체(ELF32)			---
리스트2.14	readelf -s elfsamp.o 의 결과			src/elfsamp/readelf-o-s.out
리스트2.15 재배치 엔트리(ELF32)				---
리스트2.16	readelf -r elfsamp.o 의 결과			src/elfsamp/readelf-o-r.out
리스트2.17	ELF 형식의 덤프 프로그램 예(elfdump.c)	src/elfsamp/elfdump.c
리스트2.18	elfdump elfsamp.o 의 실행결과			src/elfsamp/elfdump-o.exec
리스트2.19	elfdump elfsamp 의 		src/elfsamp/elfdump.exec
--------------------------------------------------------------------------------
리스트3.1	아카이브 헤더의 정의(ar.h 에서 발췌)		src/ar/ar.h
리스트3.2	4.4 BSD 유래의 아카이브(bsdar.a)			src/ar/bsdar.a
리스트3.3	GNU binutils 의 아카이브(gnuar.a)		src/ar/gnuar.a
리스트3.4	아카이브 파일의 덤프(readname.c)		src/ar/readname.c
리스트3.5	아카이브 파일의 해석(ardump.c)		src/ar/ardump.c
리스트3.6	오브젝트 파일(ardump.o)의 해석 예		src/ar/ardump.exec
리스트3.7	라이브러리 아카이브(/usr/lib/libc.a)의 해석 예	src/ar/ardump.exec2
리스트3.8	main() 함수(main.c)				src/link/main.c
리스트3.9	샘플 파일１(samp1.c)			src/link/samp1.c
리스트3.10	샘플 파일２(samp2.c)			src/link/samp2.c
리스트3.11	샘플 파일３(samp3.c)			src/link/samp3.c
리스트3.12	샘플 파일４(samp4.c)			src/link/samp4.c
리스트 3.13	샘플 파일２의 수정(samp2.c)		src/link/samp2d.c
---		checksym.c					src/checksym/checksym.c
--------------------------------------------------------------------------------
리스트 4.1	배열과 포인터(pointer.c)			src/pointer/pointer.c
그림 4.2		nm pointer 의 결과				src/pointer/pointer.nm
그림 4.3		objdump -h pointer 의 결과			src/pointer/pointer.od
리스트 .2	const 정의한 변수에 값을 대입한다(const.c)	src/const/const.c
리스트 4.3	const 정의한 변수에 값을 대입한다(const_sub.c)	src/const/const_sub.c
그림 4.8		nm const 의 결과					src/const/const.nm
그림 4.9		objdump -h const 의 결과				src/const/const.od
리스트 4.4	링커 스크립트의 수정				src/const/elf_i386.diff
그림 4.12		nm noconst 의 결과				src/const/noconst.nm
그림 4.13		objdump -h noconst 의 결과			src/const/noconst.od
리스트 4.5	심볼 타입에 대해(info nm 에서 발췌)	---
리스트 4.6	변수 b 의 참조(const_b.c)			src/const/const_b.c
리스트 4.7	변수 num 의 참조(layer.c)			src/layer/layer.c
리스트 4.8	변수 num 의 정의(layer_sub1.c)			src/layer/layer_sub1.c
리스트 4.9	변수 num 의 참조(layer_sub2.c)			src/layer/layer_sub2.c
그림 4.27		nm liblayer.a 의 결과				src/layer/liblayer.a.nm
그림 4.31		nm liblayer_local.a 의 결과			src/layer/liblayer_local.a.nm
그림 4.35		nm layer_lib.o 의 결과				src/layer/layer_lib.o.nm
그림 4.38		nm layer_lib_local.o 의 결과			src/layer/layer_lib_local.o.nm
리스트 4.10	변수 num 을 조작하지 않는다(layer2.c)			src/layer/layer2.c
그림 4.41		심볼이 중복되는 경우				src/layer/layer_lib2.o.comp
리스트 4.11	NetBSD/hpcsh 용 링커 스크립트(ehl-elf.x 에서 발췌)
								---
리스트 4.12	PROVIDE() 의 지정(elf_i386.x 에서 발췌)		---
리스트 4.13	심볼의 어드레스 표시(edata.c)		src/edata/edata.c
그림 4.46		objdump -h edata 의 결과				src/edata/edata.od
리스트 4.14	초기화를 임의로 수행한다(initialize.c)		src/initialize/initialize.c
그림 4.47		initialize 의 실행결과				src/initialize/initialize.comp
								src/initialize/initialize.exec
리스트 4.15	do_ctors()의 정의(crtbegin.c 에서 발췌)		---
리스트 4.16	ctor_end[] 의 정의(crtend.c 에서 발췌)		---
리스트 4.17	.ctors 섹션 정의(elf_i386.x 에서 발췌)	---
리스트 4.18	함수 자동 호출(ctors.c)			src/ctors/ctors.c
그림 4.48		ctors 의 어드레스 배치				src/ctors/ctors.comp
								src/ctors/ctors.nm
								src/ctors/ctors.od
리스트 4.19	do_dtors()의 정의(crtbegin.c 에서 발췌)		---
리스트 4.20	atexit() 를 통한 _fini() 의 등록(crt1.c:_start()에서 발췌)
								---
리스트 4.21	exit()의 정의(exit.c에서 발췌)			---
리스트 4.22	constructor, destructor 속성 사용(constructor.c)
								src/constructor/constructor.c
--------------------------------------------------------------------------------
리스트 5.1	소스 파일의 예(main.c)			src/linksamp/main.c
리스트 5.2	소스 파일의 예(lib1.c)			src/linksamp/lib1.c
리스트 5.3	소스 파일의 예(lib2.c)			src/linksamp/lib2.c
리스트 5.4	objdump 를 통한 해석(main.o)			src/linksamp/main.od
리스트 5.5	objdump 를 통한 해석(lib1.o)			src/linksamp/lib1.od
리스트 5.6	objdump 를 통한 해석(lib2.o)			src/linksamp/lib2.od
리스트 5.7	objdump 를 통한 해석(linksamp)			src/linksamp/linksamp.od
리스트 5.8	간단한 링커 스크립트의 예(sample.lds)		src/linksamp/sample.lds
리스트 5.9	objdump 를 통한 해석(otherscr)			src/linksamp/otherscr.od
--------------------------------------------------------------------------------
리스트 6.1	간단한 링커 스크립트의 예(sample.lds)		src/linksamp/sample.lds
리스트 6.2	명령 고쳐쓰기의 예(overwrite.c)			src/linksamp/overwrite.c
리스트 6.3	심볼 작성의 샘플 스크립트(addr.lds)	src/linksamp/addr.lds
리스트 6.4	심볼 작성의 샘플 프로그램(addr.c)	src/linksamp/addr.c
그림 6.6		addr 의 해석 결과(발췌)				src/linksamp/addr.od
그림 6.7		addr 의 실행결과					src/linksamp/addr.out
리스트 6.5	심볼 충돌의 샘플 스크립트(conflict.lds)	src/linksamp/conflict.lds
리스트 6.6	심볼 충돌의 샘플 프로그램(conflict.c)	src/linksamp/conflict.c
그림 6.10		conflict 의 해석 결과(발췌)			src/linksamp/conflict.od
그림 6.11		conflict 의 실행결과				src/linksamp/conflict.out
리스트 .7	정의 가능한 초기값 영역			---
리스트 6.8	정의 불가능한 초기값 영역			---
리스트 6.9	변수 작성 샘플 스크립트(valiable.lds)	src/linksamp/valiable.lds
리스트 6.10	변수 작성 샘플 프로그램(valiable.c)	src/linksamp/valiable.c
리스트 6.11	FILL()の 사용방법				---
리스트 6.12	FILLEXPの사용방법				---
그림 6.13		valiable 의 해석 결과(발췌)			src/linksamp/valiable.od
그림 6.14		valiable 의 실행결과			src/linksamp/valiable.out
리스트 6.13	섹션 작성 서식				---
리스트 6.14	섹션 기술				---
리스트 6.15	LMA 지정 샘플 스크립트(lma.lds)		src/linksamp/lma.lds
그림 6.16		lma 의 해석결과(발췌)				src/linksamp/lma.od
그림 6.17		nm lma 의 결과					src/linksamp/lma.nm
--------------------------------------------------------------------------------
리스트 7.1	링크 순서의 샘플 프로그램(ordermain.c, ...)
								src/order/ordermain.c
								src/order/order1.c
								src/order/order2.c
리스트 7.2	중복 심볼 샘플 프로그램(dupmain.c, ...)
								src/duplicate/dupmain.c
								src/duplicate/duptest1.c
								src/duplicate/duptest2.c
								src/duplicate/dup1.c
								src/duplicate/dup2.c
리스트 7.3	바이너리 데이터의 담금질(binary.c)		src/binary/binary.c
그림 7.21		nm binary 의 결과				src/binary/binary.nm
그림 7.22		objdump -h binary 의 결과			src/binary/binary.od
리스트 7.4	.incbin 의 사용(incbin.s)			src/binary/incbin.s
리스트 7.5	usr/initramfs_data.S 안의 코멘트		---
리스트 7.6	링커 스크립트(bindata.scr)			src/binary/bindata.scr
--------------------------------------------------------------------------------
리스트 8.1	ELF 형식의 로드부분(imgact_elf.c)		---
그림 8.1		man execl 에서 발췌				---
그림 8.2		readelf -S /bin/ls 의 결과			src/loader/ls.shdr
그림 8.3		readelf -S /usr/bin/gcc 의 결과			src/loader/gcc.shdr
리스트 8.2	링커 스크립트의 수정				src/loader/ldscript.diff
그림 8.4		readelf -l /bin/ls 의 결과			src/loader/ls.phdr
리스트 8.3	플래그 변경용 프로그램(chflg.c)		src/loader/chflg.c
리스트 8.4	_start()의 선두부분(crt1.c)			---
리스트 8.5	(stack_sample.c)				src/stack/stack_sample.c
리스트 8.6	(stack_sample.s)				src/stack/stack_sample.s
리스트 8.7	간이 로더(loader.c)				src/loader/loader.c
리스트 8.8	로드 대상 샘플 프로그램(sample.c)	src/loader/sample.c
그림 8.7		간이 로더의 실행결과				src/loader/loader.out
--------------------------------------------------------------------------------
리스트 9.1	코어덤프 작성용 프로그램(down.c)		src/core/down.c
그림 9.3		실행형식의 섹션 구성			src/core/down.readelf
그림 9.4		코어덤프 해석				src/core/core.readelf
리스트 9.2	elf_puthdr()					---
리스트 9.3	elf_putnote()					---
리스트 9.4	Elf_Note 의 정의(elf_common.h)			---
리스트 9.5	prstatus_t 의 정의(procfs.h)			---
리스트 9.6	struct reg 의 정의(reg.h)			---
리스트 9.7	struct fpreg 의 정의(reg.h)			---
리스트 9.8	prpsinfo_t 의 정의(procfs.h)			---
그림 9.5		코어덤프 해석				src/core/nm.out
그림 9.6		변수 count 부근의 덤프				---
리스트 9.9	실행재개용 프로그램(continue.c)		src/continue/continue.c
리스트 9.10	실행재개의 실험용 샘플 프로그램(calc.c)	src/continue/calc.c
그림 9.7		calc.c 의 실행결과				src/continue/calc.comp
								src/continue/calc.out
그림 9.10		실행의 재개					src/continue/continue.out
리스트 9.A	_setjmp()/_longjmp() 의 이용 예(setjmp.c)		src/setjmp/setjmp.c
그림 9.A		setjmp.c 의 실행결과				src/setjmp/setjmp.out
리스트 9.B	_setjmp()/_longjmp() 소스(_setjmp.S)	src/setjmp/_setjmp.S
리스트 9.C	_setjmp() 호출후에 스택이 파괴되는 예(setjmp2.c)
								src/setjmp/setjmp2.c
그림 9.B		setjmp2.c 의 실행결과				src/setjmp/setjmp2.out
--------------------------------------------------------------------------------
리스트 10.1	역어셈블리용 샘플 프로그램(rasm.c)	src/rasm/rasm.c
리스트 10.2	역어셈블리용 샘플 프로그램(rasm2.c)	src/rasm/rasm2.c
리스트 10.3	rasm.o 의 역어셈블 결과			src/rasm/rasm.o.ra
리스트 10.4	rasm 의 역어셈블 결과				src/rasm/rasm.ra
리스트 10.5	rasm.o 의 섹션, 재배치 테이블, 심볼 테이블
								src/rasm/rasm.o.re
리스트 10.6	rasm2.o 의 심볼 테이블			src/rasm/rasm2.o.re
리스트 10.7	rasm 의 심볼 테이블				src/rasm/rasm.re
리스트 10.8	i386 의존 정의(/usr/include/machine/elf.h)	---
리스트 10.9	weak 심볼 정의의 예(weak.c)			src/weak/weak.c
리스트 10.10	글로벌 심볼의 정의 예(global.c)		src/weak/global.c
리스트 10.11	weak 심볼 사용의 예(main.c)			src/weak/main.c
리스트 10.12	global.o 를 링크한 경우의 실행결과		src/weak/global.exec
리스트 10.13	global.o 를 링크하지 않은 경우의 실행결과	src/weak/noglobal.exec
리스트 10.14	실행형식 global 의 심볼 테이블(발췌)	src/weak/global.nm
리스트 10.15	실행형식 noglobal 의 심볼 테이블(발췌)	src/weak/noglobal.nm
리스트 10.16	라이브러리 아카이브를 사용한 경우의 실행결과	src/weak/global_a.exec
리스트 10.17	man syscall					---
리스트 10.18	__syscall() 의 호출				---
리스트 10.19	syscall()의 정의(발췌)				---
리스트 10.20	시스템콜용 라이브러리(syscall.s)		src/linker/syscall.s
리스트 10.21	문자열 표시용 라이브러리(service.c)		src/linker/service.c
리스트 10.22	스타트업(crt.c)				src/linker/crt.c
리스트 10.23	샘플 프로그램(main.c)			src/linker/main.c
리스트 10.24	샘플 프로그램(sample.c)			src/linker/sample.c
리스트 10.25	샘플 프로그램(sample2.c)			src/linker/sample2.c
리스트 10.26	샘플 프로그램의 실행결과			src/linker/sample.exec
리스트 10.27	심볼 해결용 라이브러리(linklib.h)		src/linker/linklib.h
리스트 10.28	심볼 해결용 라이브러리(linklib.c)		src/linker/linklib.c
리스트 10.29	다이나믹 링커(dynlink.c)			src/linker/dynlink.c
리스트 10.30	다이나믹 링커의 실행결과			src/linker/dynlink.exec
리스트 10.31	실행형식용 링커(linker.c)			src/linker/linker.c
리스트 10.32	실행형식용 링커의 실행결과			src/linker/linker.exec
리스트 10.33	링커로 작성한 실행 형식의 실행 결과		src/linker/sample2.exec
리스트 10.34	PowerPC용 심볼 해결				---
--------------------------------------------------------------------------------
리스트 11.1	라이브러리 사용 샘플 프로그램(sample.c)	src/shared/sample.c
리스트 11.2       라이브러리 사용 샘플 프로그램(main.c)	src/shared/main.c
그림 11.7		sample_shared 의 실행결과			src/shared/sample_shared.exec
그림 11.11		sample_static 의 실행결과			src/shared/sample_static.exec
그림 11.13		readelf -a sample_pic.o 의 출력결과		src/shared/sample_pic.o.re
리스트 11.3	i386의 재배치 종류(/usr/include/machine/elf.h 에서 발췌)
								---
그림 11.14		objdump -d sample_pic.o 의 출력결과		src/shared/sample_pic.o.ra
그림 11.15		readelf -a libsample.so.1 의 출력결과		src/shared/libsample.so.1.re
리스트 11.4	Elf32_Dyn 의 정의(elf32.h 에서 발췌)		---
리스트 11.5	d_tag 가 가진 값(elf_common.h 에서 발췌)		---
그림 11.16		libsample.so.1 의 .got 섹션 덤프 결과	src/shared/libsample.so.1.got
그림 11.17		objdump -d libsample.so.1의 출력결과		src/shared/libsample.so.1.ra
그림 11.18		readelf -a sample_shared의 출력결과		src/shared/sample_shared.re
그림 1.19		objdump -d sample_shared의 출력결과		src/shared/sample_shared.ra
그림 11.20		sample_shared .got 섹션의 덤프 결과	src/shared/sample_shared.got
리스트 11.6	.rtld_start의 정의(i386/rtld_start.S)		---
리스트 11.7	_rtld()의 정의(rtld.c)				---
리스트 11.8	init_rtld()의 정의(rtld.c)			---
리스트 11.9	digest_phdr()의 정의(rtld.c)			---
리스트 11.10	digest_dynamic()의 정의(rtld.c)			---
리스트 11.11	relocate_objects()의 정의(rtld.c)		---
리스트 11.12	init_pltgot()의 정의(i386/reloc.c)		---
리스트 11.13	_rtld_bind()의 정의(rtld.c)			---
리스트 11.14	dlopen()/dlsym()/dlclose()의 사용 예(dlopen.c)	src/shared/dlopen.c
그림 11.21		dlopen.c 의 실행결과				src/shared/dlopen.exec
리스트 11.15	dlopen()의 정의(rtld.c)				---
--------------------------------------------------------------------------------
```

이상
