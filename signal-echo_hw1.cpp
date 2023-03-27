#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <ucontext.h>
#include <pwd.h>

void handler(int n, siginfo_t* s_i, void* context){
  pid_t pid;
  uid_t uid;
  struct passwd* pw;
  
  ucontext_t* ucontext = static_cast<ucontext_t*>(context);
  
    pid = s_i->si_pid;
    uid = s_i->si_uid;
    pw = getpwuid(uid);
  
    std::cout << "Received a SIGUSR1 signal from process [" << pid << "] ";
    std::cout << " executed by [" << uid << "] "; 
  
    std::cout << "[" << pw << "]" << std::endl;
   
    std::cout << "State of the context:" << std::endl;
    std::cout << "EIP = [" << ucontext->uc_mcontext.gregs[REG_RIP] << "]";
    std::cout << ", EAX = [" << ucontext->uc_mcontext.gregs[REG_RAX] << "]";
    std::cout << ", EBX = [" << ucontext->uc_mcontext.gregs[REG_RBX] << "]" << std::endl;
}

int main(int argc, char** argv) {
  
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_sigaction = &handler;

  if(sigaction(SIGUSR1, &sa, NULL) < 0){
    std::cerr << "Error detected " << strerror(errno) << std::endl;
    exit(errno);
  }

  while(true){
    sleep(10);
  }
  
  return 0;
  
}