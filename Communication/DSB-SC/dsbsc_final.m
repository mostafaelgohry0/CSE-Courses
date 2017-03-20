
                                %   DSB-SC modualtion 
                                
%Data signal is sinc signal with 1000 Hz and 3 volt
%amplitude, while carrier signal is also cos signal
%with 1 MHz and 3 volt  

                                
  pkg load signal ;              %  load signal  package   
  
  
                                                       
fm=1000;                                                          %     message frequency 
fc=1000000;                                                       %      carrier  frequency 
st=1/(20*fc) ;                                                     % sample rate
t=-.0005:st:.0005;                           



    %  modualtion   
    
                                                   
m=3*sinc(2*pi*fm*t);                             % the message 
c=3*cos(2*pi*fc*t);                              % the carrier 
s=m.*c;                                         %  s




%%%%  demoduation    

r=s.*c;                            %   after demodulted     r(t)




%%%    using  low pass filter   


lf=fir1(100,125/1000000);



%lf=fir1(1000,[0 .1]);

low_filter_r=filter(lf,4.5,r);






%  converting  to  frequency  domain  

f=linspace(-fm/2,fm/2,length(t));               %  calcuting  the frequency


m_freq=fftshift(fft(m));                        % message  in frequency  domain

c_freq=fftshift(fft(c));                        % carray  in frequency domain

s_freq=fftshift(fft(s));                      % s   in frequency domain



r_freq=fftshift(fft(r));                      %   r  in frequency  domain


low_filter_r_freq=fftshift(fft(low_filter_r));   %   r  after LPF in frequency domain




%%%%%%%%%%%%%%% checking points   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%   1st check point    displaying the data and carrier signal in time and  frequency domain before modulation.

figure    %  message 

subplot(2,1,1);plot(t,m);title("message  signal in time ");grid on ;  
subplot(2,1,2);plot(f,abs(m_freq));title(" f message  in frequency"); grid on ;  axis([-2 2 ]);

figure    %  carrier  

subplot(2,1,1);plot(t,c);title("carrier signal in time ");  grid on ;    axis( [-10/fc 10/fc -4 4 ] );
subplot(2,1,2);plot(f,abs(c_freq));title("f carray in frequency"); grid on ;




%  2nd check point, displaying the modulated signal in time and frequency domain after modulation.

figure     % modulated  signal  s 

subplot(2,1,1);plot(t,s);title("modulation   in time ");grid on ;    axis( [-100/fc 100/fc -10 10 ] );    
subplot(2,1,2);plot(f,abs(s_freq));title(" modulation in frequency"); grid on ;



% 3rd check point, displaying efficiency of the technique.



% 4th check point, displaying the modulated and carrier signal in time and
% frequency domain before demodulation.
  
  
  figure 
  
subplot(4,1,1);plot(t,c);title("carrier signal in time ");  grid on ;    axis( [-10/fc 10/fc -4 4 ] );
subplot(4,1,2);plot(f,abs(c_freq));title("f carray in frequency"); grid on ;

subplot(4,1,3);plot(t,s);title("modulation   in time ");grid on ;    axis( [-100/fc 100/fc -10 10 ] );    
subplot(4,1,4);plot(f,abs(s_freq));title(" modulation in frequency"); grid on ;



%% 5th check point, displaying the received signals in time and frequency domain after demodulation.

figure 

subplot(2,1,1) ,plot(t,r),title("r(t) at time "); grid on ;
subplot(2,1,2) ,plot(f,abs(r_freq)),title("r(t) at frequency"); grid on ; 




%%  6th check point, displaying the received signals in time and frequency
%%   domain after using appropriate filter.

figure 

subplot(2,1,1) ,plot(t,low_filter_r),title(" recived  sing in time domain \" final\" "); grid on ;
subplot (2,1,2),plot(f,abs(low_filter_r_freq)) ,title ("recived signal in frequency domain ");grid on ; axis ([-2 2]);


%%  7 th check point, removing any DC offset and displaying the received
%%  signals in time and frequency domain.

%%%  in dsb-sc there is no  dc 




%%%  final  check  ploting message   before and after  modualtion  

figure
 
plot(t,m,"g", t,low_filter_r,"r");title("ploting message   before and after  modualtion  ");grid on ;