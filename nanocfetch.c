PLACEHOLDER
PLACEHOLDER
PLACEHOLDER
if [[ -f "/bedrock/etc/bedrock-release" ]] && [[ $PATH == */bedrock/cross/* ]]; then
  echo $(tput setab 9) $(tput setab 1) $(tput sgr0) ":| distro | "$(cat /bedrock/etc/bedrock-release)
else
 if [[ -f "/etc/os-release" ]]; then
  echo $(tput setab 9) $(tput setab 1) $(tput sgr0) ":| distro | "$(cat /etc/os-release | awk -F= '{print $2;exit}'| awk -F\" '{print $1,$2}')
 else
  echo $(tput setab 9) $(tput setab 1) $(tput sgr0) ":| distro | "$(uname -o)
 fi
fi
echo $(tput setab 10) $(tput setab 2) $(tput sgr0) ":| kernel | "$(uname -r)
echo $(tput setab 11) $(tput setab 3) $(tput sgr0) ":| device | "$(uname -n) $(uname -m)
echo $(tput setab 12) $(tput setab 4) $(tput sgr0) ":| host   | "$(cat /sys/devices/virtual/dmi/id/product_name)
echo $(tput setab 13) $(tput setab 5) $(tput sgr0) ":| shell  | "$(basename $SHELL)
echo $(tput setab 14) $(tput setab 6) $(tput sgr0) ":| wm     | "$(id=$(xprop -root -notype | awk '$1=="_NET_SUPPORTING_WM_CHECK:"{print $5}'); xprop -id "${id}" -notype -f _NET_WM_NAME 8t | grep "_NET_WM_NAME = " | cut --delimiter=' ' --fields=3 | cut --delimiter='"' --fields=2)
echo $(tput setab 15) $(tput setab 7) $(tput sgr0) ":| gtk    | "$(grep 'gtk-theme-name' $HOME/.config/gtk-3.0/settings.ini | cut -d' ' -f 3)
echo $(tput setab 8) $(tput setab 0) $(tput sgr0) ":| pkgs   | "$(ls -1q /usr/bin | wc -l)
