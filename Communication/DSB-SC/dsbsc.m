
pkg load signal ;
% modulation   
                                                     
fm=1000;                                                          %     message frequency 
fc=1000000;                                                       %      carrier  frequency 
st=1/(20*fc) ;                                                     % sample rate
t=-.0005:st:.0005;                           

                                               
m=3*sinc(2*pi*fm*t);                             % the message 
c=3*cos(2*pi*fc*t);                              % the carrier 
s=m.*c;                                         %  s(m)

%  plotint  in time  domain 
figure(1) 
subplot(3,1,1);plot(t,m);title("message  signal in time ");grid on ;    
subplot(3,1,2);plot(t,c);title("carrier signal in time ");  grid on ;    axis( [-10/fc 10/fc -4 4 ] );
subplot(3,1,3);plot(t,s);title("modulation   in time ");grid on ;    axis( [-100/fc 100/fc -10 10 ] );


%  ploting int frequency  domain  

f=linspace(-fm/2,fm/2,length(t));               %  calcuting  the frequency


m_freq=fftshift(fft(m));                        % message  in frequency

c_freq=fftshift(fft(c));                        % carray  in frequency

s_freq=fftshift(fft(s));                      % s(m)   in frequency



figure (2) ;
subplot(3,1,1);plot(f,abs(m_freq));title(" f message  in frequency"); grid on ;  axis([-2 2 ]);
subplot(3,1,2);plot(f,abs(c_freq));title("f carray in frequency"); grid on ;
subplot(3,1,3);plot(f,abs(s_freq));title(" modulation in frequency"); grid on ;






%%%%  demoduation    

r=s.*c;                            %   after demodulted     r(t)

r_freq=fftshift(fft(r));                % in frequency  
%r_freq=fft(r);
figure 3 ;

subplot(2,1,1) ,plot(t,r),title("r(t) at time "); grid on ;
subplot(2,1,2) ,plot(f,abs(r_freq)),title("r(t) at frequency"); grid on ; 



%%%    using  low pass filter   


%lf=fir1(1000,110/1000);
lf=fir1(1000,[0 .1]);


low_filter_r=filter(lf,5,r);
low_filter_r_freq=fftshift(fft(low_filter_r));

figure 
subplot(2,1,1) ,plot(t,m),title(" message   send "); grid on ;
subplot(2,1,2) ,plot(t,low_filter_r),title("message  recive  final"); grid on ;


