./push_swap `ruby -e "puts (-100..100).to_a.shuffle.join(' ')"`
ARG="`ruby -e "puts (-100..100).to_a.shuffle.join(' ')"`"; ./push_swap $ARG | ./checker -n $ARG

