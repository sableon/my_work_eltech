        JMP   start             ; ���室 �� ��砫� �ணࠬ�� , �� ����室���
                                ; ��� <�᢮�������� ������ ����� ��� ��ࠡ��稪��
                                ; ���뢠���
start:                          ; � ���ॡ���� � ����� ࠡ���
        ORG   100H              ; ��४⨢� �뤥����� ����� �ணࠬ�;  ����
                                ; �ᯮ�������
                                ; ࠡ�祩 �ணࠬ��

        MOV   sp,#AH            ; sp  - ��� ॣ���� 

Repeate:                        ; ��⪠ ������
        MOV   A, P0             ; �⥭�� ������ �� ���� � ��������

        MOV   C, A.7            ; ����ᨬ 7 ��� �������� � c
        ANL   C, A.3            ; c AND A.3
        JC    www
        JB    A.3, xxx
        JB    A.7, xxx
        JMP   www


xxx:    MOV    P1,A             ; �뤠� १���� �� ���� �뢮��
        JMP    loop


www:    MOV     P1, #00
        JMP    loop

loop:   DJNZ  RR,Repeate        ;  ������� ��� ����� ������ �᫨ ��� �� ���௠��
        JMP $
END
