#!/usr/bin/env bash

# QMK_REPO="https://github.com/qmk/qmk_firmware.git"
QMK_REPO_PATH="$HOME/github/qmk_firmware"

MY_REPO_PATH="$HOME/my/qmk_keymaps"

OS=$(uname -s)
case "${OS}" in
    "Darwin")
        unset BIND_OPT
        ;;
    "Linux")
        BIND_OPT=( -o nonempty )
        ;;
esac

function inject {
    for fp_keyboard in "${MY_REPO_PATH}/keyboards/"*
    do
        keyboard=$(basename "${fp_keyboard}")
        if [ ! -d "${QMK_REPO_PATH}/keyboards/${keyboard}" ]
        then
            mkdir "${QMK_REPO_PATH}/keyboards/${keyboard}"
        fi
        bindfs "${BIND_OPT[@]}" {"${MY_REPO_PATH}","${QMK_REPO_PATH}"}/keyboards/"${keyboard}"
    done
}

function override {
    bindfs "${BIND_OPT[@]}" {"${MY_REPO_PATH}","${QMK_REPO_PATH}"}/keyboards
}

#override
inject
