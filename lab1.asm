	LIST	p=18f452
	INCLUDE	<P18F452.INC>	        

	    cblock  0x8A
		r0
		r1
		r2
		r3
		r4
		r5
		r6
		r7
		r8
		r9
	    endc
	EXTERN MapIndex	
	    ORG	    0x80
MapName
    movlw	0x50	    ;P
    movwf	r0
    movlw	0x6C	    ;l
    movwf	r1
    movlw	0x75	    ;u
    movwf	r2
    movlw	0x73	    ;s
    movwf	r3
    movlw	0x55	    ;U
    movwf	r4
    movlw	0x6C	    ;l
    movwf	r5
    movlw	0x74	    ;t
    movwf	r6
    movlw	0x72	    ;r
    movwf	r7
    movlw	0x61	    ;a
    movwf	r8
    movlw	0x00	    ;[NULL]
    movwf	r9
getMapChar
    movlw	0x0A
    CPFSGT	MapIndex
    goto	getChar
    goto	getDefault	

getChar
    movlw	0x8A
    addwf	MapIndex, 0	;add the result to the working register
    movwf	FSR0L		;move wreg to fsr0l
    movf	INDF0, 0	;move the indirectly addressed value to the working register
    return
	    
getDefault
    movlw	0xFF
    return
    
	GLOBAL	MapName	
	GLOBAL	getMapChar
	    
	END