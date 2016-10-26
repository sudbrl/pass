<?php
/** @var $icons \Theme\Icons */
/** @var $group \SP\DataModel\GroupData */
/** @var $groupUsers \SP\DataModel\GroupUsersData */
?>

<div id="fancyContainer" align="center">
    <h2 class="midround"><?php echo $header; ?></H2>

    <form method="post" name="frmGroups" id="frmGroups" class="form-action" data-onsubmit="appMgmt/save">
        <table class="fancydata">
            <tbody>
            <tr>
                <td class="descField"><?php echo _('Nombre'); ?></td>
                <td class="valField">
                    <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                        <input id="name" name="name" type="text" required
                               class="mdl-textfield__input mdl-color-text--indigo-400"
                               maxlength="50" value="<?php echo $group->getUsergroupName(); ?>">
                        <label class="mdl-textfield__label"
                               for="name"><?php echo _('Nombre del grupo'); ?></label>
                    </div>
                </td>
            </tr>

            <tr>
                <td class="descField"><?php echo _('Descripción'); ?></td>
                <td class="valField">
                    <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                        <input id="description" name="description" type="text"
                               class="mdl-textfield__input mdl-color-text--indigo-400"
                               maxlength="50" value="<?php echo $group->getUsergroupDescription(); ?>">
                        <label class="mdl-textfield__label"
                               for="description"><?php echo _('Descripción del grupo'); ?></label>
                    </div>
                </td>
            </tr>

            <tr>
                <td class="descField"><?php echo _('Usuarios'); ?></td>
                <td class="valField">
                    <select id="selUsers" name="users[]" multiple="multiple" class="select-box"
                            title="<?php echo _('Usuarios'); ?>">
                        <option value=""><?php echo _('Seleccionar Usuarios'); ?></option>
                        <?php foreach ($users as $id => $name): ?>
                            <?php $selected = (\SP\Util\Util::checkInObjectArray($groupUsers, 'getUsertogroupUserId', $id)) ? 'selected' : ''; ?>
                            <option
                                value="<?php echo $id; ?>" <?php echo $selected; ?>><?php echo $name; ?></option>
                        <?php endforeach; ?>
                    </select>
                </td>
            </tr>

            <?php if ($customFields): ?>
                <?php include $this->includeTemplate('aux-customfields', 'common'); ?>
            <?php endif; ?>

            </tbody>
        </table>

        <input type="hidden" name="activeTab" value="<?php echo $activeTab ?>"/>
        <input type="hidden" name="onCloseAction" value="<?php echo $onCloseAction ?>"/>
        <input type="hidden" name="itemId" value="<?php echo $group->getUsergroupId(); ?>"/>
        <input type="hidden" name="actionId" value="<?php echo $actionId; ?>"/>
        <input type="hidden" name="sk" value="<?php echo $sk; ?>">
        <input type="hidden" name="isAjax" value="1">
    </form>
    <div id="resCheck"><span id="resFancyAccion"></span></div>
    <div class="action-in-box">
        <button
            class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored <?php echo $icons->getIconSave()->getClassButton(); ?>"
            form="frmGroups" title="<?php echo $icons->getIconSave()->getTitle(); ?>">
            <i class="material-icons"><?php echo $icons->getIconSave()->getIcon(); ?></i>
        </button>
    </div>
</div>
<script type="text/javascript">
    sysPassApp.sk.set("<?php echo $sk; ?>");
</script>